#include<iostream>
#include<map>
#include<set>
#include<iterator>

using namespace std;

int main()
{
	int t,a,b,c,d,e;
	while(true)
	{
		cin>>t;
		if(!t)break;
		map<set<int>,int>mp;
		map<set<int>,int>::iterator it;
		int mx=0;
		while(t--)
		{
			set<int>s;
			cin>>a>>b>>c>>d>>e;
			s.insert(a);
			s.insert(b);
			s.insert(c);
			s.insert(d);
			s.insert(e);
			if(mp.find(s)==mp.end())
			{
				mp[s]=1;
				if(mx==0)mx=1;
			}
			else
			{
				mp[s]++;
				if(mx<mp[s])mx=mp[s];
			}
		}
		int y=0;
		for(it=mp.begin();it!=mp.end();++it)
		{
			if(it->second==mx)y++;
		}
		cout<<mx*y<<"\n";
	}
	return 0;
}
