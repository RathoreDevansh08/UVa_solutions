#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

vector<int>a[17];
int prime[32];
void preprocess()
{
	int f;
	prime[1]=0;
	for(int i=2;i<=31;i++)
	{
		f=1;
		for(int j=2;j<=i-1;j++)
		{
			if(i%j==0){f=0;break;}
		}
		if(f)prime[i]=1;
		else prime[i]=0;
	}
	
	for(int i=1;i<=16;i++)
	{
		for(int j=1;j<=16;j++)
		{
			if(i!=j)
			{
				if(prime[i+j])
				{
					a[i].push_back(j);
				}
			}
		}
	}
}

vector<int>::iterator it;
void bt(int n,int k,vector<int>vis,int n0, vector<int>l)
{
	if(n0==n)
	{
		if(!prime[1+l[n0]])return;
		for(int h=1;h<=n0;h++)cout<<l[h]<<" ";
		cout<<"\n";
		return;
	}
	for(auto& e:a[k])
	{
		if(e<=n && vis[e]==0)
		{
			l[n0+1]=e;
			vis[e]=1;
			bt(n,e,vis,n0+1,l);
			vis[e]=0;
		}	
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	preprocess();
	
	int n,c=1;
	while(cin>>n)
	{
		if(c!=1)cout<<"\n";
		cout<<"Case "<<c++<<":\n";
		vector<int>vis(n+1,0);
		vector<int>l(n+1,0);
		l[1]=1;vis[1]=1;
		bt(n,1,vis,1,l);
	}
	
	return 0;
}
