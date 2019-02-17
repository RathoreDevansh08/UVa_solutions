#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		n=n-2;m=m-2;
		
		cout<<(int)ceil((float)n/3)*(int)ceil((float)m/3)<<"\n";
	}
	return 0;
} 
