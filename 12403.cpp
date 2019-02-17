#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	long int v;
	long long int amt=0;
	string st;
	scanf("%d",&t);
	while(t--)
	{
		cin>>st;
		if(st=="donate")
		{
			scanf("%li",&v);
			amt+=v;
		}
		else
		{
			printf("%lli\n",amt);
		}
	}
	return 0;
}
