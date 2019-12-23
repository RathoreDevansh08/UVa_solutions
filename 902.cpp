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

int kmpPreprocess_Search(string T, string P, int n, int m)
{
	//Preprocess
	
	int i=0, j=-1, b[n+100];
	b[0]=-1;
	while(i<m)
	{
		while(j>=0 && P[i]!=P[j]) j=b[j];
		i++;j++;
		
		b[i]=j;
	}


	//Search	
	
	i=0;j=0;
	int cnt=0;
	while(i<n)
	{
		while(j>=0 && T[i]!=P[j]) j=b[j];
		i++;j++;
		
		if(j==m)
		{
			//cout<<"P found at index "<<i-j<<" in T\n";
			cnt++;
			j=b[j];
		}
	}
	
	return cnt;
}

int kmp(string T, string P)
{
	int n=T.length(), m=P.length();
	return kmpPreprocess_Search(T,P,n,m);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(cin>>m)
	{
		map<string, int>mp;
		
		cin>>st;
		n=st.length();
		
		if(n<m || m<=0) {cout<<"\n";continue;}
		if(n==m) {cout<<st<<"\n";continue;}
		
		string g, an="";
		int u=m-1, ans=-1, l;
		while(u<n)
		{
			g=st.substr(u-(m-1),m);
			mp[g]++;
			
			if(ans<mp[g])
			{
				ans=mp[g];an=g;
			}
			u++;
		}
		
		cout<<an<<"\n";
	}
	return 0;
}
