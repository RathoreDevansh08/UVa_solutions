#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;++i) 
#define frn(i,a,b) for(int i=a;i>=b;--i)
typedef long long int ll;
typedef vector<int> vi;

string st;
int t,m,n,a,b,f=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	char input[10][100];
	int pow[]={1,2,4,8,16,32,64,128};
	while(n--)
	{
		fr(i,0,9) cin>>input[i];
		st="";
		
		m = strlen(input[0]);
		fr(i,1,m-2)
		{
        	a=0;
        	fr(j,1,8)
        	{
        	    if(input[j][i]=='\\') a+=(int)pow[j-1];
        	}
        	st+=(char)a;
    	}
    	cout<<st<<"\n";
	}
	return 0;
}
