#include<iostream>
#include<vector>
using namespace std;

#define inf 10000000
int t,n,m,a,b,c=1;
int ad[101][101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				ad[i][j]=inf;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			ad[a][b]=1;
			ad[b][a]=1;
		}
		cin>>a>>b;
		
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					ad[i][j]=min(ad[i][j],ad[i][k]+ad[k][j]);
					
		int mx=0;
		for(int i=0;i<n;i++)
		{
			ad[i][i]=0;
		}
		for(int i=0;i<n;i++)
		{
			mx=max(mx,ad[a][i]+ad[i][b]);
		}
		cout<<"Case "<<c++<<": "<<mx<<"\n";
	}
	return 0;
}
