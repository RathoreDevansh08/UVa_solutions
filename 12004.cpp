#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

string st;
int t,m,n,a,b,f=0,c=1;
long long int d;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		d=(long long int)((n)*(n-1)/2);
		if(d%4==0) printf("%lld\n",d/4);
		else printf("%lld/2\n",d/2);
	}
	return 0;
}
