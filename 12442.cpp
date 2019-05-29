#include<bits/stdc++.h>

using namespace std;

vector<bool> vis;
int t, n, u, v;
vector<int> to, sum;

void solve() 
{
	for(int i=0; i<n; i++) 
	{
		if(sum[i] == -1) 
		{
			int total = 0;
			vis.assign(n, false);
			int current = i;
			while(vis[current] == false && sum[current] == -1) 
			{
				vis[current] = true;
				total++;
				current = to[current];
			}
			if(current != i) 
			{
				sum[i] = sum[current] + total;
			}
			else if(current == i) 
			{
				vis.assign(n, false);
				while(vis[current] == false) 
				{
					vis[current] = true;
					current = to[current];
					sum[current] = total;
				}
			}
		}
	}
}

int main() 
{
	int count = 1, ans, nans;
	scanf("%d", &t);
	while(t--) 
	{
		nans = 0;
		scanf("%d", &n);
		to.assign(n, -1);
		sum.assign(n, -1);
		vis.assign(n, false);
		for(int i=0; i<n; i++) 
		{
			scanf("%d%d", &u, &v);
			to[u-1] = v-1;
		}
		solve();
		for(int i=0; i<n; i++) 
		{
			if(nans < sum[i]) 
			{
				nans = sum[i];
				ans = i+1;
			}
		}
		printf("Case %d: %d\n", count++, ans);
	}
	return 0;
}
