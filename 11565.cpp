#include<bits/stdc++.h>

using namespace std;
 
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
 
    int n,A,B,C;
    cin>>n;
    while(n--)
    {
        cin>>A>>B>>C;
 
        int f=0,x,y,z; 
        for(x=-50;x<=50;x++)
        {
            for(y=-20;y<=20;y++)
            {
                if(x!=y && ((x*x+y*y)+(A-x-y)*(A-x-y)==C))
                {
                    int t=x*y;
                    if(!t) continue;
 
                    z=B/t;
                    if(z!=x && z!=y && x+y+z==A)
                    {
                        if(!f)
                        {
                            int a[3] = {x, y, z};
                            sort(a, a+3);
                            cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<"\n";
                            f=1;
                            break;
                        }
                    }
                }
            }
        }
        if(!f) cout<<"No solution.\n";
    }
    return 0;
}
