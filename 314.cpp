#include <cstdio>
#include <set>
#include <map>
#include <queue>
#define MP make_pair
using namespace std;
 
typedef pair<int, int> P;
 
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int word[] = {'s', 'e', 'n', 'w'};
int r0, c0, r1, c1;
 
int BFS(int dir, set<P> ok) {
  int i;
  queue<pair<P, int> > q;
  map<pair<P, int>, int> visit;
  visit[MP(MP(r0, c0), dir)] = 0;
  q.push(MP(MP(r0, c0), dir));
  while (!q.empty()) {
    int r = q.front().first.first, c = q.front().first.second, dis = visit[q.front()];
    if (r == r1 && c == c1) return dis;
    int d = q.front().second, times;
    q.pop();
    P p;
    for (times = 1; times < 4; times++) {
      p = MP(r + dr[d] * times, c + dc[d] * times);
      if (!ok.count(p)) break;
      if (visit.count(MP(p, d))) continue;
      visit[MP(p, d)] = dis + 1;
      q.push(MP(p, d));
    }
    int left, right;
    right = (d + 1) % 4;
    p = MP(r, c);
    if (ok.count(p) && !visit.count(MP(p, right))) {
      visit[MP(p, right)] = dis + 1;
      q.push(MP(p, right));
    }
    left = (d + 4 - 1) % 4;
    if (!visit.count(MP(p, left))) {
      visit[MP(p, left)] = dis + 1;
      q.push(MP(p, left));
    }
  }
  return -1;
}
 
int main() {
  int i, j, r, c;
  while (scanf("%d%d", &r, &c) && r || c) {
    int grid[50][50];
    set<P> ok;
    for (i = 0; i < r; i++)
      for (j = 0; j < c; j++) {
        scanf("%d", &grid[i][j]);
        if (!grid[i][j]) ok.insert(MP(i, j));
      }
    for (i = 0; i < r; i++)
      for (j = 0; j < c; j++)
        if (grid[i][j]) {
          ok.erase(MP(i, j));
          ok.erase(MP(i, j + 1));
          ok.erase(MP(i + 1, j));
          ok.erase(MP(i + 1, j + 1));
        }
    for (i = 0; i <= r; i++) {
      ok.erase(MP(i, 0));
      ok.erase(MP(i, c));
    }
    for (i = 0; i <= c; i++) {
      ok.erase(MP(0, i));
      ok.erase(MP(r, i));
    }
    char dir[20];
    scanf("%d%d%d%d%s", &r0, &c0, &r1, &c1, dir);
    if (!ok.count(MP(r1, c1))) {
      puts("-1");
      continue;
    }
    int d;
    for (d = 0; d < 4; d++)
      if (word[d] == dir[0]) break;
    printf("%d\n", BFS(d, ok));
  }
  return 0;
}
