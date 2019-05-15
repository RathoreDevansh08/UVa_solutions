#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	char x;
	int t,n,c=1;
	cin>>t;
	while(t--)
	{
		cin>>n;
		
		int total=0,cover=-1;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			if(cover<i && x=='.')
			{
				cover=i+2;
				total++;
			}
		}	
		cout<<"Case "<<c++<<": "<<total<<"\n";
	}	
	
	return 0;
}	
