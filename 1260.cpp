#include<iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int count=0;
		int a[n];
		
		cin>>a[0];
		for(int i=1;i<n;i++)
		{
			cin>>a[i];
			for(int j=0;j<i;j++)
			{
				if(a[j]<=a[i])count++;
			}
		}
		cout<<count<<"\n";
	}
	return 0;
}
