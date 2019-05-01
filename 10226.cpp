#include<iostream>
#include<map>
#include<iterator>

using namespace std;

int main()
{
	int n;
	cin>>n;
	string st,sp;
	getline(cin,sp);
	n++;
	while(n--)
	{
		int i=0,t=0;
		map<string,int>mp;
		map<string,int>::iterator it;
		while(true)
		{
			getline(cin,st);
			if(st.length()==0)break;
			//cout<<i++<<st<<st.length()<<"\n";
			t++;
			if(mp.find(st)==mp.end())
			{
				mp.insert(pair<string,int>(st,1));
			}
			else
			{
				mp[st]+=1;
			}
		}
		
		if(t!=0)
		for(it=mp.begin();it!=mp.end();++it)
		{
			cout<<it->first<<" ";
			printf("%0.4f\n",(it->second)/((float)t)*100.0000);
		}
		if(t!=0)cout<<"\n";
	}
	return 0;
}
