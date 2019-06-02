#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
#define for(i,a,b) for(int i=a;i<b;i++) 
typedef long long int ll;
typedef vector<int> vi;

int t,m,n,r,a,b,f=0,c=1,w;double u;
vi taken(1001);
priority_queue<pair<double,int>>pq;
int states;double road, rail;
vector<pair<int,int>>co;
double dist(pair<int,int>p1, pair<int,int>p2)
{
	return sqrt(pow(p1.first - p2.first,2) + pow( p1.second - p2.second,2));
}

void process(int i)
{
	taken[i]=1;
	for(j,0,n)
	{
		if(!taken[j]) pq.push(make_pair((double)(-1.0)*dist(co[i],co[j]),-1*j));
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		cin>>n>>r;
		
		for(i,0,n) 
		{
			cin>>a>>b;
			co.pb(make_pair(a,b));
			taken[i]=0;
		}
		
		process(0);
		states=1;road=rail=0.0;
		while(!pq.empty())
		{
			pair<int,int>fr=pq.top();pq.pop();
			u=(double)(-1.0)*fr.first;w=-1*fr.second;
			if(!taken[w] && u<=r) {road+=u;process(w);}
			else if(!taken[w]) 
			{
				rail+=u;
				states++;
				//pq.clear();
				process(w);
			}
		}
		cout<<"Case #"<<c++<<": "<<states<<" "<<(int)round(road)<<" "<<(int)round(rail)<<"\n";
		co.clear();
	}
	return 0;
}
