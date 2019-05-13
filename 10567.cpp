#include<bits/stdc++.h>

using namespace std;

int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(NULL);

	int q,j,a,b,f,n,m;
	string st,s;
	
	getline(cin,st);
	n=st.length();
	
	vector<char>v(n);
	vector<char>::iterator it;
	for(int i=0;i<n;i++)v[i]=st[i];
	 	
	cin>>q;
	getline(cin,s);
	for(int i=0;i<q;i++) 
	{
		getline(cin,s);
		j=0;f=1;m=0;
		while(s[j])
		{
			it=find(v.begin()+m,v.end(),s[j]);
			if(it==v.end()){f=0;break;}
			if(j==0){a=it-v.begin();}
			m=it-v.begin()+1;
			if(v.begin()+m>=v.end() && s[j+1]){f=0;break;}
			j++;
		}
		if(!f) cout<<"Not matched\n";
		else
		{
			b=it-v.begin();
			cout<<"Matched "<<a<<" "<<b<<"\n";
		}
	}
 	
 	return 0;
}
