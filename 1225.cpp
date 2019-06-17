#include <cstdio>
int main()
{
    int tst, i, j, k;
    scanf("%d", &tst);
    while(tst--)
    {
        int n, ara[10];
        for(i=0; i<10; i++) ara[i]=0;
        scanf("%d", &n);
        for(i=1; i<=n; i++)
        {
            j = i;
            while(j!=0)
            {
                k=j%10;
                ara[k]++;
                j/=10;
            }
        }
        for(i=0; i<9; i++) printf("%d ", ara[i]);
        printf("%d\n", ara[9]);
    }
    return 0;
}

