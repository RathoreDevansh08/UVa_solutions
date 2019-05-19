#include<iostream>
#include<string.h>

using namespace std;

int n,q,d,m;
int a[201], memory[20][201][201];

int dp(int m,int k,int sum)
{
	if(m==0)
	{
		if(sum==0) return 1;
		else return 0;
	}
	if(m>0 && k==n) return 0;
	if(memory[m][k][sum]!=-1) return memory[m][k][sum];
	
	memory[m][k][sum]= dp(m-1,k+1,(sum+a[k])%d) + dp(m,k+1,sum);
	return memory[m][k][sum];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int c=1;
	while(cin>>n>>q && (n || q))
	{
		cout<<"SET "<<c++<<":\n";
		for(int i=0;i<n;i++) cin>>a[i];
		for(int j=0;j<q;j++)
		{
			memset(memory,-1,sizeof(memory));
			cin>>d>>m;
			cout<<"QUERY "<<j+1<<": "<<dp(m,0,0)<<"\n";
		}
	}
	
	return 0;
}
