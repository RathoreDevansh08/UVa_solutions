#include<bits/stdc++.h>

using namespace std;

int main()
{
	int deg,t,d,k;
	int arr[21];
	cin>>t;
	while(t--)
	{
		cin>>deg;
		for(int i=0;i<=deg;i++)cin>>arr[i];
		cin>>d>>k;
		
		int pos=1,inc=d,c;
		for (c=1;c<=k;++pos,inc+=d)
		{
			c+=inc;
		}
		
		unsigned long long int e=0;
		for(int i=0;i<=deg;i++)
		{
			e+=arr[i]*pow(pos-1,i);
		}
		cout<<e<<"\n";
		
	}
	return 0;
}
