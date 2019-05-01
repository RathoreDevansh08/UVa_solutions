#include <iostream>

using namespace std;

#define MX 1000100

int main() 
{
    int n,m,a[MX],b[MX];
    int i,j,count;
    while(cin >> n >> m)
    {
        if(n==0 && m==0) break;
        for(i=1;i<=n;i++) cin>>a[i];
        for(i=1;i<=m;i++) cin>>b[i];
        
        count=0;
        i=j=1;
        while(i<=n && j<=m)
        {
            while(j<=m && b[j]<a[i]) j++;
            if (j>m) break;
            if (a[i]==b[j])
            {
                count++;j++;
            }
            i++;
        }
        cout<<count<<endl;
    }
    return 0;
}
