#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int>v1(3);
	vector<int>v2(2);
	while(true)
	{
		cin>>v1[0]>>v1[1]>>v1[2]>>v2[0]>>v2[1];
		if(v1[0]==0&&v1[1]==0&&v1[2]==0&&v2[0]==0&&v2[1]==0)break;
		int f=0;
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		if(v1[2]>v2[1])
		{
			if(v1[1]>v2[0])
			{
				cout<<"-1\n";
			}
			else
			{
				for(int i=v1[1]+1;i<=52;i++)
				{
					if(i!=v1[0] && i!=v1[1] && i!=v1[2] && i!=v2[0] && i!=v2[1])
					{
						cout<<i<<"\n";f=1;break;
					}
				}
				if(f==0)cout<<"-1\n";
			}	
		}
		else if(v1[2]>v2[0])
		{
			if(v1[0]>v2[0])
			{for(int i=v1[2]+1;i<=52;i++)
				{
					if(i!=v1[0] && i!=v1[1] && i!=v1[2] && i!=v2[0] && i!=v2[1])
					{
						cout<<i<<"\n";f=1;break;
					}
					
				}if(f==0)cout<<"-1\n";}
			else if(v1[1]>v2[0])
			{for(int i=v1[2]+1;i<=52;i++)
				{
					if(i!=v1[0] && i!=v1[1] && i!=v1[2] && i!=v2[0] && i!=v2[1])
					{
						cout<<i<<"\n";f=1;break;f=1;
					}
					
				}if(f==0)cout<<"-1\n";}
			else
			{for(int i=v1[1]+1;i<=52;i++)
				{
					if(i!=v1[0] && i!=v1[1] && i!=v1[2] && i!=v2[0] && i!=v2[1])
					{
						cout<<i<<"\n";f=1;break;f=1;
					}
					
				}if(f==0)cout<<"-1\n";}
			
		}
		else
		{
			for(int i=1;i<=52;i++)
			{
				if(i!=v1[0] && i!=v1[1] && i!=v1[2] && i!=v2[0] && i!=v2[1])
				{
					cout<<i<<"\n";f=1;break;f=1;
				}
				
			}
			if(f==0)cout<<"-1\n";
		}
	}
	return 0;
}
