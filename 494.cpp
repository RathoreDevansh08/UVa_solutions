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

string st, k;
int t,m,n,a,b,f=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(getline(cin, st))
	{
		int count=0, j=0;
		while(st[j])
		{
			if(isalpha(st[j]))
			{
				while(isalpha(st[j])) j++;
				count++;
			}
			j++;
		}
		
		cout<<count<<"\n";
	}
	
	return 0;
}
