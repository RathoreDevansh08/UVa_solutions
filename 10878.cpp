#include<iostream>
#include<vector>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;i++) 
#define frn(i,a,b) for(int i=a;i>=b;--i) 
typedef long long int ll;
typedef vector<int> vi;

string st;
int t,m,n,a,b,f=0;
int solve(string s) 
{
    b=1, a=0;
    frn(i,9,1)
        if(s[i]!='.') 
        {
            if(s[i]=='o') a+=b;
            b*=2;
        }
    return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	getline(cin, st);
	while(getline(cin, st))
	{
		if(st[0]=='_') return 0;
		
		cout<<(char)solve(st);
	}
	return 0;
}
