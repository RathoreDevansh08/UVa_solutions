#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,mx,sum;
	while(cin>>n && n)
	{
		mx=0;sum=0;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
			if(sum>mx) mx=sum;
			else if(sum<0) sum=0;
		}
		if(mx>0) cout<<"The maximum winning streak is "<<mx<<".\n";
		else cout<<"Losing streak.\n";
	}
	
	return 0;
}
