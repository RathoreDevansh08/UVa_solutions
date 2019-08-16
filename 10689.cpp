#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

string st;
int t,m,n,a,b,f=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	
	while(t--)
	{
		cin>>a>>b>>n>>m;
		
		ll fib[15005], k=pow(10,m);
		fib[0]=a;fib[1]=b;
		fr(i,2,15004) fib[i]=(fib[i-1]+fib[i-2])%k;
		
		if(m==1)
		{
			n=n%60;
			cout<<fib[n]%10<<"\n";
		}
		else if(m==2)
		{
			n=n%300;
			cout<<fib[n]%100<<"\n";
		}
		else if(m==3)
		{
			n=n%1500;
			cout<<fib[n]%1000<<"\n";
		}
		else
		{
			n=n%15000;
			cout<<fib[n]%10000<<"\n";
		}
	}
	return 0;
}
