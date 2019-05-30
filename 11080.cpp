#include<iostream>
#include<vector>
using namespace std;

#define inf 1000000007
#define pb push_back
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

int t,n,m,a,b,fl,d;
vi col(201,0);
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
	
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		
		vi ad[n];
		fr(i,0,n-1) col[i]=-1;
		fr(i,0,m-1)
		{
			cin>>a>>b;
			ad[a].pb(b);
			ad[b].pb(a);
		}
		fl=0;d=0;
		fr(i,0,n-1)
		{
			if(col[i]==-1){ dfs(i,0,ad);
			if(fl) break;
			else
			{
				a=0;b=0;
				fr(i,0,n-1)
				{
					if(col[i]==0){col[i]=-2;a++;}
					else if(col[i]==1) {col[i]=-2;b++;}
				}	
				if(a!=0 && b!=0)d+=min(a,b);
				else d+=max(a,b);
			}}
		}
		if(fl) cout<<"-1\n";
		else cout<<d<<"\n";
	}
	return 0;
}
