#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,mx,k=0,l=0;
	while(cin>>n && n)
	{
		if(k)cout<<"\n";
		k=1;
		
		vector<int>a(n);
		vector<int>fr(1000005,0);
		
		mx=-1;
		for(int i=0;i<n;i++) {cin>>a[i];fr[a[i]]++;mx=max(mx,fr[a[i]]);}
		
		sort(a.begin(),a.end());
		cout<<mx<<"\n";
		vector<int>bag[mx];
		
		for(int i=0;i<n;i++) bag[i%mx].push_back(a[i]);
		
		for(int i=0;i<mx;i++)
		{
			l=0;
			for(auto e:bag[i])
			{
				if(l)cout<<" ";
				l=1;
				cout<<e;
			}
			cout<<"\n";
		}
	}
	
	return 0;
}
