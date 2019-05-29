#include<iostream>
#include<vector>
#include<map>

using namespace std;

int m,n,a,b,c1,c2,c3,mx;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(cin>>m>>n)
	{
		char ar[m][n];
		int con[m][n];
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				cin>>ar[i][j];
			}
		cin>>a>>b;
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				if(ar[i][j]==ar[a][b]) con[i][j]=-1;
				else con[i][j]=-2;
			}
		
		int col=0;
		map<int,int>mp;
		mp[0]=0;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				c1=-1;c2=-1;
				if(con[i][j]==-1)
				{
					if(i!=0 && con[i-1][j]>=0) c1=con[i-1][j];
					if(j!=0 && con[i][j-1]>=0) c2=con[i][j-1];
					
					if(c1==-1 && c2==-1)
					{
						con[i][j]=++col;
						mp[col]=0;					
					}
					else if(c1==-1) con[i][j]=c2;
					else if(c2==-1) con[i][j]=c1;
					else if(c1==c2) con[i][j]=c1;
					else
					{
						c3=min(c1,c2);
						con[i][j]=c3;
						for(int i=0;i<m;i++)
							for(int j=0;j<n;j++)
								if(con[i][j]==c1 || con[i][j]==c2) con[i][j]=c3;
					}
				}
			}
		}
		for(int i=0;i<m;i++)
		{
			c1=con[i][0];c2=con[i][n-1];
			if(c1>=0 && c2>=0 && c1!=c2)
			{
				c3=min(c1,c2);
				for(int i=0;i<m;i++)
					for(int j=0;j<n;j++)
						if(con[i][j]==c1 || con[i][j]==c2) con[i][j]=c3;
			}
		}
		
		mx=0;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(con[i][j]>=0 && con[i][j]!=con[a][b]) {mp[con[i][j]]++;mx=max(mx,mp[con[i][j]]);}
		
		cout<<mx<<"\n";		
	}
	return 0;
}
