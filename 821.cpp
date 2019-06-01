#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;

#define inf 1000000007
#define pb push_back
#define for(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

int t,m,n,a,b,f=0;
int ad[101][101];
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	
	while(cin>>a>>b && a && b)
	{
		for(i,0,100)
			for(j,0,100)
				ad[i][j]=10000;
		set<int>s;
		
		s.insert(a-1);s.insert(b-1);
		ad[a-1][b-1]=1;
		while(cin>>a>>b && a && b) {ad[a-1][b-1]=1;s.insert(a-1);s.insert(b-1);}
		
		for(k,0,100)
			for(i,0,100)
				for(j,0,100)
					ad[i][j]=min(ad[i][j],ad[i][k]+ad[k][j]);
					
		m=0;
		n=s.size();
		for(i,0,100)
			for(j,0,100)
				if(ad[i][j]<10000 && i!=j)
					{m+=ad[i][j];}
		//cout<<m<<" "<<n<<"\n";
		printf("Case %d: average length between pages = %0.3f clicks\n",++f,(float)m/(n*(n-1)));	
	}
	return 0;
}
