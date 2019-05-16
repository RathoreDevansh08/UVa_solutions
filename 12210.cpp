#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int b,s,c=1,minage;
	while(cin>>b>>s)
	{
		if(!b && !s) break;
		
		minage=70;
		vector<int>B(b),S(s);
		for(int i=0;i<b;i++) {cin>>B[i];minage=min(minage,B[i]);}
		for(int j=0;j<s;j++) cin>>S[j];
		
		if(s>=b) {cout<<"Case "<<c++<<": 0\n";continue;}
		else cout<<"Case "<<c++<<": "<<b-s<<" "<<minage<<"\n";
	}	
	return 0;
}
