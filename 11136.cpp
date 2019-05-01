#include<iostream>
#include<set>
#include<iterator>

using namespace std;

int main()
{
	int n,t,x;
	while(true)
	{
		cin>>n;
		if(!n)break;
		
		long int cost=0;
		multiset<int>ms;
		multiset<int>::iterator it1,it2;
		for(int i=0;i<n;i++)
		{
			cin>>t;
			for(int j=0;j<t;j++)
			{
				cin>>x;
				ms.insert(x);
			}
			it1=ms.upper_bound(-1);
			it2=ms.end();
			it2--;
			cost+=*it2-*it1;
			ms.erase(it1);ms.erase(it2);
		}
		cout<<cost<<"\n";
	}
	return 0;
}
