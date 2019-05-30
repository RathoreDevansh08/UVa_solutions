#include<iostream>
#include<vector>
using namespace std;

#define inf 1000000007
#define pb push_back
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

int t,n,m,a,b,fl;
vi col(301,0);
void dfs(int i, int c, vi ad[])
{
	col[i]=c;
	for(auto e:ad[i])
	{
		if(col[e]==-1) dfs(e,1-c,ad);
		else if(col[e]==c) {fl=1;return;}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(cin>>n && n)
	{
		vi ad[n];
		fr(i,0,n-1) col[i]=-1;
		while(cin>>a>>b && a && b)
		{
			ad[a-1].pb(b-1);
			ad[b-1].pb(a-1);
		}
		//if(n%3!=0) {cout<<"NO\n";continue;}
	
		fl=0;
		fr(i,0,n-1)
		{
			if(col[i]==-1)
			{ 
				dfs(i,0,ad);
				if(fl) break;
				else
				{
					a=0;
					fr(i,0,n-1)
					{
						if(col[i]==0 || col[i]==1){col[i]=-2;a++;}
					}
					//if(a%3!=0) {fl=1;break;}	
				}
			}
		}
		if(fl) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
