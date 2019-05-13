#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
 	cin.tie(NULL);
	
	vector<int>::iterator it1,it2,it3;
	int n,m,a,f;
	while(cin>>n)
	{
		vector<int>v(n);
		for(int i=0;i<n;i++) cin>>v[i];
		cin>>m;
		
		sort(v.begin(),v.end());
		
		it1=lower_bound(v.begin(),v.end(),m/2);
		
		if(*it1==m/2) it1=it1;
		else if(it1!=v.begin()) it1--;
		it2=it1+1;
		f=0;
		while(it1!=v.begin())
		{
			it3=find(it2,v.end(),m-*it1);
			
			if(it3!=v.end())
			{
				f=1;
				cout<<"Peter should buy books whose prices are "<<*it1<<" and "<<*it3<<".\n\n";
				break;
			}
			it1--;
		}
		if(!f)
		{
			cout<<"Peter should buy books whose prices are "<<*it1<<" and "<<m-*it1<<".\n\n";
		}
	}
	return 0;
}
