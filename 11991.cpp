#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m,v,k,x;
	while(cin>>n>>m)
	{
		map<int,vector<int>>mp;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			if(mp.find(x)==mp.end())
			{
				vector<int>f;
				f.push_back(i);
				mp.insert(pair<int,vector<int>>(x,f));
			}
			else
			{
				mp[x].push_back(i);
			}
		}
		for(int j=0;j<m;j++)
		{
			cin>>k>>v;
			if(k<=mp[v].size())cout<<mp[v][k-1]<<"\n";
			else cout<<"0\n";
		}
	}
	return 0;
}
