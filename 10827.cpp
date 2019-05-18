#include<iostream>

using namespace std;

int a[160][160];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t,n;
	long int x,mx;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
				a[i+n][j]=a[i][j+n]=a[i+n][j+n]=a[i][j];
			}
		}

		for(int i=0;i<2*n;i++)
		{
			for(int j=0;j<2*n;j++)
			{
				if(i>0) a[i][j]+=a[i-1][j];
				if(j>0) a[i][j]+=a[i][j-1];
				if(i>0 && j>0) a[i][j]-=a[i-1][j-1];
			}
		}

		mx = -999999999;

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int l=i;l<n+i && l<2*n;l++) 
					for(int m=j;m<n+j && m<2*n;m++)
					{
						x=a[l][m];
						if(i>0) x-=a[i-1][m];
						if(j>0) x-=a[l][j-1];
						if(i>0 && j>0) x+=a[i-1][j-1];
						
						if(x>mx) mx=x;
					}
		cout<<mx<<"\n";
	}
	return 0;

}
