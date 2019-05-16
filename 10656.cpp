#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,x,f;
	while(cin>>n && n)
	{
		f=0;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			if(x!=0)
			{
				if(f)cout<<" ";
				f=1;
				cout<<x;
			}
		}
		if(!f) cout<<"0\n";
		else cout<<"\n";
	}
	return 0;
}
