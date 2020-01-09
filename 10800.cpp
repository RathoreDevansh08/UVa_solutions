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

string st;
int t,m,n,a,b,f=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cas=1,mn,mx;
	
	cin>>t;
	while(t--)
	{
		cin>>st;
		n=st.length();
		cout<<"Case #"<<cas++<<":\n";
		
		int ar[n]={0}, en[n]={0};
		if(st[0]=='R') en[0]=1;
		else if(st[0]=='F') en[0]=-1, ar[0]=-1;
		
		mn=min(ar[0], en[0]);
		mx=0;
		fr(i,1,n-1)
		{
			if(st[i]=='R')
			{
				ar[i]=en[i-1];
				en[i]=ar[i]+1;
			} 
			else if(st[i]=='C')
			{
				ar[i]=en[i-1];
				en[i]=ar[i];
			}
			else
			{
				ar[i]=en[i-1]-1;
				en[i]=ar[i];
			}
			
			mn = min(mn, ar[i]);
			mn = min(mn, en[i]);
		}
		
		fr(i,0,n-1)
		{
			ar[i] = ar[i] - mn ;
			mx = max(mx, ar[i]);
			//mx = max(mx, en[i]);
		}
		
		fr(i,0,mx)
		{
			cout<<"| ";
			
			int l=-1;
			fr(j,0,n-1)
			{
				if(ar[j]==(mx-i))
				{
					fr(p,l+1,j-1) cout<<" ";
				
					if(st[j]=='R') cout<<"/";
					else if(st[j]=='F') cout<<"\\";
					else cout<<"_";
					
					l=j;
				}
			}
			
			cout<<"\n";
		}
		
		cout<<"+";
		fr(i,1,n+2) cout<<"-";
		cout<<"\n\n";
	}
	
	return 0;
}
