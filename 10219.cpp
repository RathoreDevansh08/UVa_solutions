#include<bits/stdc++.h>
using namespace std;

double lg(double n)
{
    return log(n)/log(10);
}

int main()
{
   
    long long n,k;
    double a;
    int dig;
    
    while(cin>>n>>k)
    {
        a=0;
        
        if(n-k<k)k=n-k;
        for(int i=0;i<k;i++) a+=lg(n-i)-lg(i+1);
        dig=floor(a)+1;
        
        cout<<dig<<"\n";
    }
    
    return 0;
}
