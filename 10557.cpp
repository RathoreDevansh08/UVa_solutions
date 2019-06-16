#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
#include <algorithm>
using namespace std;

bool bfs(int n, int s, int e, const vector< vector<int> >& rooms)
{
  vector<bool> visited(n, false);
  queue<int> q;
  visited[s] = true;
  q.push(s);
  while (!q.empty()) {
    int i = q.front(); q.pop();
    if (i == e)
      return true;
    for (vector<int>::const_iterator j = rooms[i].begin(), k = rooms[i].end();
      j != k; ++j)
      if (!visited[*j]) {
        visited[*j] = true;
        q.push(*j);
      }
  }
  return false;
}

bool bellman_ford(int n,
  const vector<int>& energies, const vector< pair<int, int> >& doors,
  const vector< vector<int> >& rooms)
{
  if (n == 1)
    return true;
  // initialize the graph
  vector<long long> distances(n, numeric_limits<int>::max());
  distances[0] = -100;
  // relax the edges repeatedly
  for (int i = 0; i < n - 1; i++) {
    for (size_t j = 0, e = doors.size(); j < e; j++) {
      const pair<int, int>& d = doors[j];
      if (distances[d.first] + energies[d.first] < min(0LL, distances[d.second]))
        distances[d.second] = distances[d.first] + energies[d.first];
    }
    if (distances[n - 1] < 0)
      return true;
  }
  // check for negative-weight cycles
  for (size_t i = 0, e = doors.size(); i < e; i++) {
    const pair<int, int>& d = doors[i];
    if (distances[d.first] + energies[d.first] < min(0LL, distances[d.second]) &&
      bfs(n, 0, d.first, rooms) && bfs(n, d.second, n - 1, rooms))
        // cycle is reachable both from start and to finish
      return true;
  }
  return false;
}

int main()
{
  while (true) {
    int n;
    cin >> n;
    if (n == -1)
      break;
    vector<int> energies(n); // energies[i] is the energy of i-th room
    vector< pair<int, int> > doors(n);
      // there is a one-way door form doors[].first to doors[].second
    vector< vector<int> > rooms(n);
    for (int i = 0; i < n; i++) {
      int e;
      cin >> e;
      energies[i] = -e;
      int j;
      cin >> j;
      for (int k = 0; k < j; k++) {
        int l;
        cin >> l;
        doors.push_back(make_pair(i, l - 1));
        rooms[i].push_back(l - 1);
      }
    }
    cout << (bellman_ford(n, energies, doors, rooms) ?
      "winnable\n" : "hopeless\n");
  }
  return 0;
}
