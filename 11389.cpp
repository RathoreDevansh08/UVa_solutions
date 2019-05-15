#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,d,r;
	while(cin>>n>>d>>r)
	{
		if(n==0 && d==0 && r==0)break;
		
		vector<int>mo(n),ev(n);
		for(int i=0;i<n;i++) cin>>mo[i];
		for(int j=0;j<n;j++) cin>>ev[j];
		
		sort(mo.begin(),mo.end());
		sort(ev.begin(),ev.end(),greater<int>());
		
		long int cost=0,t;
		for(int i=0;i<n;i++)
		{
			t=mo[i]+ev[i];
			cost+=(t-d)>0?(t-d)*r:0;
		}
		cout<<cost<<"\n";
	}
	
	return 0;
}
