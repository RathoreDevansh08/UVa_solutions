//#pragma comment(linker, "/stack:247474112")
//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
#define fr(i,a,b) for(int i=a;i<=b;++i) 
#define frn(i,a,b) for(int i=a;i>=b;--i) 
typedef long long int ll;
typedef vector<int> vi;

int t,m,n,a,b,c,f=0;
char op, eq;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int ans=0;
	while(cin>>a)
	{
		cin>>op>>b>>eq>>s;
		//cout<<a<<"-"<<op<<"-"<<b<<"-"<<eq<<"-"<<s<<"\n";
		
		if(s=="?") continue;
		else
		{
			stringstream ss(s);
			ss>>n;
		}
		
		if(op=='+' && (a+b)==n) ans++;
		else if(op=='-' && (a-b)==n) ans++;
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
