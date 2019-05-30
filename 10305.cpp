#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int n,m,a,b;
vector<int>vis(101,0),ans;
void dfs(int i, vector<int>v[])
{
	vis[i]=1;
	for(auto e:v[i])
	{
		if(!vis[e]) dfs(e,v);
	}
	ans.push_back(i);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(cin>>n>>m)
	{
		if(n==0) break;
		vector<int>v[n];
		for(int i=0;i<n;i++) vis[i]=0;
		
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			v[a-1].push_back(b-1);
		}
		for(int i=0;i<n;i++) if(!vis[i]) dfs(i,v);
		for(int i=n-1;i>=0;--i) cout<<ans[i]+1<<" ";
		cout<<"\n";
		
		ans.clear();
	}
	return 0;
}
