#include<algorithm>
#include<cstdio>
#include<cstring>
 
using namespace std;
 
int m, n;
int p[110], f[110];
int memory[110][10000];
 
int dp(int i, int w) 
{
    if(w > m && m < 1800)
        return -1000;
    if(w > m + 200)
        return -1000;
    if(i == n) {
        if(w > m && w <= 2000)
            return -1000;
        return 0;
    }
    if(memory[i][w] != -1)
        return memory[i][w];
 
    return memory[i][w] = max(dp(i + 1, w), f[i] + dp(i + 1, w + p[i]));
}
 
int main() 
{
    while(scanf("%d %d", &m, &n) == 2) 
    {
        for(int i = 0; i < n; i++) scanf("%d %d", &p[i], &f[i]);
        memset(memory, -1, sizeof memory);
 
        printf("%d\n", dp(0, 0));
    }
}
