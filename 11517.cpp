#include<iostream>

using namespace std;

#define inf 1000000000
int t,pr,n;
int coin[102],dp[15002];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		cin>>pr>>n;
		for(int i=0;i<n;i++) cin>>coin[i];
		
		for(int i=0;i<=15000;i++) dp[i]=inf;	
		dp[0]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=15000-coin[i];j>=0;--j)
			{
				if(dp[j]<inf) dp[j+coin[i]]=min(dp[j+coin[i]],1+dp[j]);
			}
		}
		for(int i=pr;i<=15000;i++)
		{
			if(dp[i]!=inf)
			{
				cout<<i<<" "<<dp[i]<<"\n";break;
			}		
		}
	}
	return 0;
}
