#include<iostream>

using namespace std;

long int a[200][200];
long int sum,x,mx;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
				if(i>0) a[i][j]+=a[i-1][j];
				if(j>0) a[i][j]+=a[i][j-1];
				if(i>0 && j>0) a[i][j]-=a[i-1][j-1];
			}
		}
		
		mx=-130*10000;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=i;k<n;k++)
				{
					for(int l=j;l<n;l++)
					{
						x=a[k][l];
						if(i>0) x-=a[i-1][l];
						if(j>0) x-=a[k][j-1];
						if(i>0 && j>0) x+=a[i-1][j-1];
						
						if(x>mx) mx=x;
					}
				}
			}
		}
		
		cout<<mx<<"\n";
	}
	return 0;
}
