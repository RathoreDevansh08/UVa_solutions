#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	int n,x;
	cin>>n;
	while(n)
	{	
		while(true)
		{
			stack<int>s;
			queue<int>q;
			for(int i=0;i<n;i++)
			{
				cin>>x;
				if(x==0)break;
				if(i==0)
				{
					for(int y=1;y<x;y++)s.push(y);
					for(int y=x+1;y<=n;y++)q.push(y);
				}
				else
				{
					if(s.size()!=0 && x==s.top())
					{
						s.pop();
					}
					else if(q.size()!=0)
					{
						int r=q.front();
						if(r==x)q.pop();
						while(q.size()!=0 && r!=x)
						{
							r=q.front();
							q.pop();
							if(r==x)break;
							s.push(r);
						}
						if(r!=x && q.size()==0)
						{
							cout<<"No\n";
							for(int j=i+1;j<n;j++)cin>>x;
							break;
						}
					}
					else 
					{
						cout<<"No\n";
						for(int j=i+1;j<n;j++)cin>>x;
						break;
					}
				}
				if(i==n-1 && s.size()==0 && q.size()==0)
				{
					cout<<"Yes\n";
				}
			}
			if(x==0)break;
		}
		cout<<"\n";
		cin>>n;
	}
	return 0;
}
