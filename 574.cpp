#include<iostream>
#include<map>
#include<vector>

using namespace std;

int t,n,k,d;
map<vector<int>,int>mp;
void bt(int sum, int i, vector<int>v, vector<int>l)
{
	if(sum==t)
	{
		if(mp[l]==1)return;
		
		mp[l]=1;
		k=l.size();d=0;
		for(int i = 0; i < k; i++)
            {
            	if(d)cout<<"+";
            	cout<<l[i];
            	d=1;
            }
            cout<<"\n";
		return;
	}
	if(sum>t || i==n)return;
	for(int j=i;j<n;j++)
	{
			l.push_back(v[j]);
			bt(sum+v[j],j+1,v,l);
			l.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin>>t>>n)
	{
		if(n==0 && t==0)break;
		
		mp.clear();
		vector<int>v(n);
		vector<int>l;
		
		for(int i=0;i<n;i++) {cin>>v[i];}
		
		cout<<"Sums of "<<t<<":\n";
		bt(0,0,v,l);
		if(mp.size()==0) cout<<"NONE\n";
	}
	
	return 0;
}
