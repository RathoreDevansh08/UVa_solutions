#include<iostream>
#include<string>

using namespace std;

int main()
{
	string st;
	int l=1;
	while(getline(cin,st))
	{
		if(st=="end")return 0;
		
		int id=0,nos=0;
		char c[26];
		for(int i=0;i<26;i++)c[i]='Z';
		while(st[id])
		{
			int minid, min=10000;
			for(int i=0;i<26;i++)
			{
				if(c[i]>=st[id])
				{
					if(int(c[i]-st[id])<min)
					{
						minid=i;
						min=int(c[i]-st[id]);
					}
				}
			}
			c[minid]=st[id];
			if(minid+1>nos)nos++;
			id++;
		}
		cout<<"Case "<<l++<<": "<<nos<<"\n";
	}
	return 0;
}
