#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while(cin>>n)
	{
		vector<pair<int,int>>v;
		for(int i=n+1;i<=2*n;i++)
		{
			if((i*n)%(i-n)==0){v.push_back(make_pair((i*n)/(i-n),i));}
		}
		cout<<v.size()<<"\n";
		for(auto& e:v)
		{
			cout<<"1/"<<n<<" = "<<"1/"<<e.first<<" + "<<"1/"<<e.second<<"\n";
		}
	}
	return 0;
}
