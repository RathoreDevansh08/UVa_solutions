#include<iostream>
using namespace std;

int f(int b, int p, int m)
{
    if(!p) return 1;
    
    if(p%2==0)
    {
        int x=f(b,p/2,m);
        return (x*x)%m;
    }
    return ((b%m) * f(b,p-1,m))%m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int B,P,M;    
    while(cin>>B>>P>>M) cout<<f(B,P,M)<<"\n";
    return 0;
}
