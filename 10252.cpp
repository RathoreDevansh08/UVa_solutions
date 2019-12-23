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

int t,m,n,f=0;
string a, b;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(getline(cin, a))
	{
		getline(cin, b);
		
		int cnta[26]={0}, cntb[26]={0};
		string ans="";
		
		n=a.length();m=b.length();
		fr(i,0,m-1) cntb[(int)(b[i]-'a')]++;
		fr(i,0,n-1) cnta[(int)(a[i]-'a')]++;
		
		fr(i,0,25)
		{
			m=min(cnta[i], cntb[i]);
			fr(j,1,m) ans += (char)('a' + i);
		}
		
		cout<<ans<<"\n";
	}
	return 0;
}
