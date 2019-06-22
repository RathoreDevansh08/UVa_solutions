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

int gcd(int q, int w){ return w ? gcd(w, q%w) : q;}
long int lcm(long int q, long int w){ return ((q*w)/gcd(q,w));}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	getline(cin,st);
	while(n--)
	{
		vi s;m=0;
		getline(cin,st);
		stringstream ss(st);
		
		while(ss>>a) {s.pb(a);m++;}
		
		f=0;
		fr(i,0,m-2)
		{
			fr(j,i+1,m-1)
			{
				f=max(f,gcd(s[i],s[j]));
			}
		}
		cout<<f<<"\n";
	}	
	return 0;
}
