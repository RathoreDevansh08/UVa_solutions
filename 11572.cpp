#include <stdio.h>
#include <map>

using namespace std;

map<int, int> last;

int main() 
{
    int t;
    for (scanf("%d", &t); t; t--) 
    {
        int n;
        scanf("%d", &n);
        int start = 1, sol = 0;
        last.clear();
        for (int i = 1; i <= n; i++) 
        {
            int a;
            scanf("%d", &a);
            if (last[a] >= start) 
            {
                if (i - start > sol)
                    sol = i - start;
                start = last[a] + 1;
            }
            last[a] = i;
        }
        if (n + 1 - start > sol)sol = n + 1 - start;
        printf("%d\n", sol);
    }
    return 0;
}

