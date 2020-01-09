//#pragma comment(linker, "/stack:247474112")
//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
#define fr(i,a,b) for(int i=a;i<=b;++i) 
#define frn(i,a,b) for(int i=a;i>=b;--i) 
typedef long long int ll;
typedef vector<int> vi;

int t,m,n,a,b,f=0;
string wave[10];

void preProcess()
{
	wave[0]="";
	wave[1]="1";
	wave[2]="22";
	wave[3]="333";
	wave[4]="4444";
	wave[5]="55555";
	wave[6]="666666";
	wave[7]="7777777";
	wave[8]="88888888";
	wave[9]="999999999";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;

	preProcess();
	
	int flag=0;
	while(t--)
	{
		cin>>a>>f;
		
		if(!flag) flag=1;
		else cout<<"\n";
		
		fr(i,1,f-1)
		{
			fr(j,1,a)
			{
				cout<<wave[j]<<"\n";
			}
			frn(j,a-1,1)
			{
				cout<<wave[j]<<"\n";
			}
			cout<<"\n";
		}
		
		fr(j,1,a)
		{
			cout<<wave[j]<<"\n";
		}
		frn(j,a-1,1)
		{
			cout<<wave[j]<<"\n";
		}
	}
	return 0;
}
