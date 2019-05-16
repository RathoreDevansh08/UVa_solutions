#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m;
	long int cost;
	while(cin>>n>>m)
	{
		if(!n && !m)break;
		
		vector<int>head(n),knight(m);
		for(int i=0;i<n;i++) cin>>head[i];
		for(int j=0;j<m;j++) cin>>knight[j];
		
		if(m<n) cout<<"Loowater is doomed!\n";
		else
		{
			sort(head.begin(),head.end());
			sort(knight.begin(),knight.end());
			
			cost=0;
			int h=0,k=0;
			for(int i=0;i<n;i++)
			{
				for(int j=h;j<m;j++)
				{
					if(knight[j]>=head[i])
					{
						h=j+1;
						k++;
						cost+=knight[j];
						break;
					}
				}
			}
			if(k<n) cout<<"Loowater is doomed!\n";
			else cout<<cost<<"\n";
		}
	}	
	
	return 0;
}
