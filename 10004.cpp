#include<iostream>
#include<vector>
using namespace std;

#define inf 1000000007
#define pb push_back
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

int t,n,m,a,b,fl;
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
	
	while(cin>>n)
	{
		if(!n) break;
		cin>>m;
		
		vi ad[n];
		fr(i,0,n-1) col[i]=-1;
		fr(i,0,m-1)
		{
			cin>>a>>b;
			ad[a].pb(b);
			ad[b].pb(a);
		}
		fl=0;
		dfs(0,0,ad);
		if(fl) cout<<"NOT BICOLORABLE.\n";
		else cout<<"BICOLORABLE.\n";	
	}
	return 0;
}
