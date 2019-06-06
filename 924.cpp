#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define inf 1000000007
#define pb push_back
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

int t,m,n,a,b,f=0;
int maxboomsize, maxboomday;
void bfs(int j, vi ad[])
{
	vi val(n,-1);
	val[j]=0;
	
	queue<int>q;
	q.push(j);
	while(!q.empty())
	{
		a=q.front();
		q.pop();
		for(auto e:ad[a])
		{
			if(val[e]==-1)
			{
				val[e]=val[a]+1;
				q.push(e);
			}
		}
	}
	
	int days[2501]={0};
	
	fr(i,0,n-1) if(val[i]!=-1) days[val[i]]++;
	fr(i,0,2500)
	{
		if(days[i]>maxboomsize)
		{
			maxboomsize=days[i];
			maxboomday=i;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	vi ad[n];
	fr(i,0,n-1)
	{
		cin>>t;
		while(t--)
		{
			cin>>m;
			ad[i].pb(m);
		}
	}
	cin>>t;
	while(t--)
	{
		cin>>m;
		maxboomsize=maxboomday=0;
		bfs(m,ad);
		if(ad[m].size()==0) cout<<"0\n";
		else if(maxboomsize==1) cout<<"1 1\n";
		else cout<<maxboomsize<<" "<<maxboomday<<"\n";
	}
	return 0;
}
