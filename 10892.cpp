#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

string st;
int t,m,a,b,f=0;
long int n;

long int gcd(long int q, long int w){ return w ? gcd(w, q%w) : q;}
long int lcm(long int q, long int w){ return ((q*w)/gcd(q,w));}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(cin>>n && n)
	{
		vi s;
		fr(i,1,(int)sqrt(n))
		{
			if(n%i==0) {s.pb(i); if(i!=n/i)s.pb(n/i);}
		}
		
		int card=0, sz=s.size();
		fr(i,0,sz-2)
		{
			fr(j,i+1,sz-1)
			{
				if(lcm(s[i],s[j])==n) card++;
			}
		}
		cout<<n<<" "<<card+1<<"\n";
	}	
	return 0;
}
