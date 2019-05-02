#include<iostream>
#include<map>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	int t,n,a,b;
	char ch,c1,c2;
	string st;
	cin>>t;
	int k=0;
	
	while(t--)
	{
		cin>>n;
		map<int,int>mp;
		int ns=0,nus=0;
		for(int i=1;i<=n;i++)mp[i]=-1;
		
		getline(cin,st);
		while(true)
		{
			getline(cin,st);
			if(st.length()==0)break;
			stringstream ss(st);
			ss>>ch>>a>>b;
			//cout<<"==="<<ch<<a<<b<<endl;
			if(ch=='c')
			{
				if(mp[a]==-1 && mp[b]!=-1)mp[a]=mp[b];
				else if(mp[a]==-1 && mp[b]==-1){mp[a]=a;mp[b]=a;}
				else if(mp[b]==-1 && mp[a]!=-1)mp[b]=mp[a];
				else if(mp[a]!=-1 && mp[b]!=-1)
				{
					if(mp[a]!=mp[b])
					{
						int d=mp[b];
						for(int i=1;i<=n;i++)
						{
							if(mp[i]==d)mp[i]=mp[a];
						}
					}
				}
			}
			else if(ch=='q')
			{
				if(a==b)ns++;
				else if(mp[a]==mp[b] && mp[a]!=-1)ns++;
				else nus++;
			}
			//for(int i=1;i<=n;i++)cout<<mp[i]<<" ";cout<<"\n";
		}
		
		cout<<ns<<","<<nus<<"\n";
		if(t!=0)cout<<"\n";
	}
}
