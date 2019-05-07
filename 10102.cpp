#include<iostream>
#include<set>
#include<sstream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m,mi,ma;
	string st;
	while(getline(cin,st))
	{
		stringstream ss(st);
		ss>>m;
		int x;
		
		set<pair<int,int>>s1,s3;
		for(int i=0;i<m;i++)
		{
			getline(cin,st);
			for(int j=0;j<m;j++)
			{
				x=st[j];
				if(x=='1') {s1.insert(make_pair(i,j));}
				else if(x=='3') {s3.insert(make_pair(i,j));}
			}
		}
		
		ma=1;
		for(auto& i:s1)
		{
			mi=5*m;
			for(auto& j:s3)
			{
				mi=min(mi,abs(i.first-j.first)+abs(i.second-j.second));
			}
			ma=max(ma,mi);
		}
		cout<<ma<<"\n";
	}
	return 0;
}
