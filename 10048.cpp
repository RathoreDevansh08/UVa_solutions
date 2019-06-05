#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

int c, s, q, a, b, d, i, ans, cs=1;
vector<pair<int, ii> > edge;
vector<vector<ii> > span;
vi p, visited;
bool blank=false, flag=false;;

void initSet(int n)
{
	p.assign(n+1, 0);
	for(i=1;i<=n;++i)
		p[i]=i;
}
int findSet(int i)
{
	return p[i]==i?i:findSet(p[i]);
}
bool sameSet(int i, int j)
{
	return findSet(i)==findSet(j);
}
void unionSet(int i, int j)
{
	if(!sameSet(i, j))
	{
		p[findSet(i)]=p[findSet(j)];
	}
}
void dfs(int u, int sum)
{
	visited[u]=1;
	if(u==b)
	{
		ans=sum;
		flag=true;
		return;
	}
	for(int j=0;j<(int)span[u].size();++j)
	{
		ii v=span[u][j];
		if(!visited[v.first])
			dfs(v.first, max(sum, v.second));
		if(flag)
			return;
	}
}
int main()
{
	while(true)
	{
		scanf("%d %d %d", &c, &s, &q);
		if(!c && !s && !q)
			break;
		edge.clear();
		span.clear();
		span.assign(c+2, vector<ii>());
		p.clear();
		visited.clear();
		visited.assign(c+2, 0);
		initSet(c);
		while(s--)
		{
			scanf("%d %d %d", &a, &b, &d);
			edge.push_back(make_pair(d, ii(a, b)));
		}
		for(i=1;i<=c;++i)
			span[i].clear();
		sort(edge.begin(), edge.end());
		for(i=0;i<(int)edge.size();++i)
		{
			pair<int, ii> temp=edge[i];
			if(!sameSet(temp.second.first, temp.second.second))
			{
				unionSet(temp.second.first, temp.second.second);
				span[temp.second.first].push_back(ii(temp.second.second, temp.first));
				span[temp.second.second].push_back(ii(temp.second.first, temp.first));
			}
		}
		if(blank)
			putchar('\n');
		blank=true;
		printf("Case #%d\n", cs++);
		while(q--)
		{
			scanf("%d %d", &a, &b);
			flag=false;
			for(i=1;i<=c;++i)
				visited[i]=0;
			if(!sameSet(a, b))
				printf("no path\n");
			else
			{
				ans=0;
				dfs(a, ans);
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}

