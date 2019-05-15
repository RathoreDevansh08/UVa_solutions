#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int v[n];
		for(int i=0;i<n;i++) cin>>v[i];
		
		if(n==1 || n==2) {cout<<n<<"\n"; continue;}
		
		int sum=1,coins=2; 
		for(int j=1;j<n-1;j++)
		{
			if(sum+v[j]<v[j+1])
			{
				sum+=v[j];
				coins++;
			}
		}
		cout<<coins<<"\n";
	}
	
	return 0;
}
