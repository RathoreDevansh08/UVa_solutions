#include<bits/stdc++.h>

using namespace std;

int main()
{
	string st,st2,a,b;
	

	while(getline(cin,st))
	{
		getline(cin,st2);
		
		a=0;b=0;
		
		int m=st.length();
		for(int i=0;i<m;i++)
		{
			if(isalpha(st[i]))
			{
				a+=(int)(st[i]-60)
			}
		}
	}
	return 0;
}
