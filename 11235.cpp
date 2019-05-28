#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,q,x,x0,a,b,s,l,m;
	pair<int,int>p;
	while(true)
	{
		cin>>n;
		if(n==0)break;
		cin>>q;
		
		map<int,pair<int,int>>mp;
		map<int,pair<int,int>>::iterator it;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			if(mp.find(x)==mp.end())
			{
				if(i!=1)mp[x0].second=i-1;
				mp[x].first=i;
				mp[x].second=-1;
			}
			x0=x;
			if(i==n)
			{
				mp[x].second=n;
			}
		}
		for(int j=0;j<q;j++)
		{
			cin>>a>>b;
			it=mp.begin();
			s=1;l=it->second.second;
			m=s-a;
			while(l<=b)
			{
				if(s>=a)
				{
					m=max(m,l-s+1);
				}
				else if(m<=0)
				{
					m=s-a;
				}
				it++;
				if(it==mp.end())break;
				s=it->second.first;
				l=it->second.second;
			}
			if(l>b)
			{
				m=max(m,max(0,b-s+1));
			}
			
			cout<<max(1,m)<<"\n";
		}
	}
	return 0;
}
