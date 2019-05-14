#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long int t,n,d,j,k,c=0;
	cin>>t;
	while(t--)
	{
		cin>>n;n++;
		vector<long int>v(n);
		
		v[0]=0;
		for(long int i=1;i<n;i++) cin>>v[i];
		
		if(n==1) {cout<<"Case "<<++c<<": "<<v[0]<<"\n";continue;}
		
		j=n-2;
		d=v[n-1]-v[n-2];
		while(j!=0)
		{
			if(v[j]-v[j-1]==d) d++;
			if(v[j]-v[j-1]>=d+1) {d=v[j]-v[j-1];}
			j--;
		}
		cout<<"Case "<<++c<<": "<<d<<"\n";
	}
	
	return 0;
}
