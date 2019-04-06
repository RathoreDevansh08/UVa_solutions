#include<iostream>
#include<list>

using namespace std;

int main()
{
	string st;
	while(getline(cin,st))
	{
		list<char>A;
		list<char>::iterator it;
		int n=st.length();
		int t=0,i=0;
		while(i!=n)
		{
			if(st[i]=='['){t=1;it=A.begin();}
			else if(st[i]==']')t=0;
			else
			{
				if(t==0)A.push_back(st[i]);
				else
				{
					A.insert(it,st[i]);	
				}
			}
			i++;
		}
		for(it=A.begin();it!=A.end();it++)		
			cout<<*it;
		cout<<"\n";
	}
	return 0;
}
