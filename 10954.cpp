#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int n,x;
	while(true)
	{
		cin>>n;
		if(!n)break;
		
		long int cost=0;
		priority_queue<int, vector<int>, greater<int>>pq;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			pq.push(x);
		}
		
		long int sum=0;
		while(pq.size()>1)
		{
			sum=pq.top();
			pq.pop();
			sum+=pq.top();
			pq.pop();
			pq.push(sum);
			cost+=sum;
		}
		cout<<cost<<"\n";
	}
	return 0;
}
