#include<iostream>

using namespace std;

int main()
{
	long int m,n;
	while(true)
	{
		cin>>m>>n;
		int c0=0,c1=0,c2=0,c3=0;
		if(m==0 || n==0)return 0;
		
		char a[m][m],b[n][n];
		for(int i=0;i<m;i++)
			for(int j=0;j<m;j++)
				cin>>a[i][j];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>b[i][j];
				
		for(int i=0;i<=m-n;i++)
		{
			for(int j=0;j<=m-n;j++)
			{
				if(a[i][j]==b[0][0] && a[i][j+n-1]==b[0][n-1] && a[i+n-1][j]==b[n-1][0] && a[i+n-1][j+n-1]==b[n-1][n-1])
				{
					int f=1;
					for(int l=0;l<n;l++)
					{
						for(int h=0;h<n;h++)
						{
							if(a[i+l][j+h]!=b[l][h]){f=0;break;}
						}
						if(f==0)break;
					}
					if(f==1)c0++;
				}
			}
		}
		for (int i = 0; i < n/ 2; i++)
		{ 
			for (int j = i; j < n - i - 1; j++)
			{ 
			    char te=b[i][j];
			    b[i][j] = b[n - 1 - j][i]; 
			    b[n - 1 - j][i] = b[n - 1 - i][n - 1 - j]; 
			    b[n - 1 - i][n - 1 - j] = b[j][n - 1 - i]; 
			    b[j][n - 1 - i] = te; 
			} 
		} 
		
		for(int i=0;i<=m-n;i++)
		{
			for(int j=0;j<=m-n;j++)
			{
				if(a[i][j]==b[0][0] && a[i][j+n-1]==b[0][n-1] && a[i+n-1][j]==b[n-1][0] && a[i+n-1][j+n-1]==b[n-1][n-1])
				{
					int f=1;
					for(int l=0;l<n;l++)
					{
						for(int h=0;h<n;h++)
						{
							if(a[i+l][j+h]!=b[l][h]){f=0;break;}
						}
						if(f==0)break;
					}
					if(f==1)c1++;
				}
			}
		}
		
		for (int i = 0; i < n/ 2; i++)
		{ 
			for (int j = i; j < n - i - 1; j++)
			{ 
			    char te=b[i][j];
			    b[i][j] = b[n - 1 - j][i]; 
			    b[n - 1 - j][i] = b[n - 1 - i][n - 1 - j]; 
			    b[n - 1 - i][n - 1 - j] = b[j][n - 1 - i]; 
			    b[j][n - 1 - i] = te; 
			} 
		} 
		
		for(int i=0;i<=m-n;i++)
		{
			for(int j=0;j<=m-n;j++)
			{
				if(a[i][j]==b[0][0] && a[i][j+n-1]==b[0][n-1] && a[i+n-1][j]==b[n-1][0] && a[i+n-1][j+n-1]==b[n-1][n-1])
				{
					int f=1;
					for(int l=0;l<n;l++)
					{
						for(int h=0;h<n;h++)
						{
							if(a[i+l][j+h]!=b[l][h]){f=0;break;}
						}
						if(f==0)break;
					}
					if(f==1)c2++;
				}
			}
		}
		
		for (int i = 0; i < n/ 2; i++)
		{ 
			for (int j = i; j < n - i - 1; j++)
			{ 
			    char te=b[i][j];
			    b[i][j] = b[n - 1 - j][i]; 
			    b[n - 1 - j][i] = b[n - 1 - i][n - 1 - j]; 
			    b[n - 1 - i][n - 1 - j] = b[j][n - 1 - i]; 
			    b[j][n - 1 - i] = te; 
			} 
		} 
		
		for(int i=0;i<=m-n;i++)
		{
			for(int j=0;j<=m-n;j++)
			{
				if(a[i][j]==b[0][0] && a[i][j+n-1]==b[0][n-1] && a[i+n-1][j]==b[n-1][0] && a[i+n-1][j+n-1]==b[n-1][n-1])
				{
					int f=1;
					for(int l=0;l<n;l++)
					{
						for(int h=0;h<n;h++)
						{
							if(a[i+l][j+h]!=b[l][h]){f=0;break;}
						}
						if(f==0)break;
					}
					if(f==1)c3++;
				}
			}
		}
		
		cout<<c0<<" "<<c1<<" "<<c2<<" "<<c3<<"\n";		
	}
	return 0;
}
