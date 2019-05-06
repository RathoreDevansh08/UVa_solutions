#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m,x,k=0,ms,sum=0;
	while(cin>>n)
	{
		if(!n)return 0;
		
		k++;
		cout<<"Case "<<k<<":\n";
		
		vector<int>v(n);
		for(int i=0;i<n;i++)
		{
			cin>>x;
			v[i]=x;
		}
		sort(v.begin(),v.end());
		
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cin>>x;
			ms=1000000007;
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<j;k++)
				{
					if(ms>=abs(v[j]+v[k]-x))
					{
						ms=abs(v[j]+v[k]-x);
						sum=v[j]+v[k];
					}
				}
			}
			cout<<"Closest sum to "<<x<<" is "<<sum<<".\n";
		}
	}
	return 0;
}
