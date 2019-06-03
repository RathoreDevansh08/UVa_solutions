#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
//#define for(i,a,b) for(int i=a;i<b;i++) 
typedef long long int ll;
typedef vector<int> vi;

int t,m,n,r,a,b,f=0,c=1,w,u;
vi taken(200005);
priority_queue<pair<int,int>>pq;
long int mst_cost=0,tot;

void process(int i, vector<pair<int,int>>ad[])
{
	taken[i]=1;
	for(auto j:ad[i])
	{
		if(!taken[j.second]) pq.push(make_pair(-1*j.first,-1*j.second));
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin>>n>>m && n && m)
	{
		tot=0;
		vector<pair<int,int>>ad[n];
		for(int i=0;i<n;i++) taken[i]=0;
		for(int i=0;i<m;i++) 
		{
			cin>>a>>b>>w;
			ad[a].pb(make_pair(w,b));ad[b].pb(make_pair(w,a));
			tot+=w;
		}
		process(0,ad);
		mst_cost=0;
		while(!pq.empty())
		{
			pair<int,int>fr=pq.top();pq.pop();
			w=-1*fr.first;
			u=-1*fr.second;
			if(!taken[u]) {mst_cost+=w;process(u,ad);}
		}
		cout<<tot-mst_cost<<"\n";
	}
	return 0;
}
