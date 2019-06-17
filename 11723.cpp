#include<iostream>
using namespace std;

int main()
{    
    int a,b,d,T,c=1;
    
    while(cin>>a>>b && a)
    {
        if(a<=b) {cout<<"Case "<<c++<<": "<<0<<"\n"; continue;}
        
        d=a/b-1;
        if(d<=26) cout<<"Case "<<c++<<": "<<d<<"\n";
        else cout<<"Case "<<c++<<": impossible\n";
    }
    return 0;
}
