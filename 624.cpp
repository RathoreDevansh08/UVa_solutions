#include<bits/stdc++.h>

using namespace std;

const int MMAX=0x7fffffff;

vector<int> v,t;
int n,m,a[21],MAX;
void dfs(int x, int sum)
{
	if(x==m)
	{
		if(sum>MAX && sum<=n)
		{
			MAX=sum;
			t=v;
		}
		return;
	}
	v.push_back(a[x]);
	dfs(x+1,sum+a[x]);
	v.pop_back();
	dfs(x+1,sum);
}

int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(NULL);
 	
 	while(cin>>n)
	{
		cin>>m;
		MAX=-MMAX;
		for(int i=0;i<m;i++) cin>>a[i];
		
		dfs(0,0);
		
		for(int i=0;i<t.size();i++) cout<<t[i]<<" ";
		cout<<"sum:"<<MAX<<"\n";
	}
 	return 0;
}
