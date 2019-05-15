#include<cstdio>
#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int>given(8),pos(8);
set<vector<int>>s;

bool place_allowed(int r,int c)
{
	for(int i=0;i<c;i++)
	{
		if((r==pos[i]) || (abs(r - pos[i])==abs(c-i))) return false;
	}
	return true;
}

void solve(int c)
{
	if(c==8){s.insert(pos);return;}
	for(int r=0;r<8;r++)
	{
		if(place_allowed(r,c))
		{
			pos[c] = r;
			solve(c+1);
		}
	}
	return;
}

int mini()
{
	int ans=-1,val;
	for(auto x:s)
	{
		val=0;
		for(int i=0;i<8;i++)
		{
			val+=(x[i]==given[i] ?0:1);
		}
		if(ans==-1 || val<ans) ans=val;
	}
	return ans;
}

int main()
{
	int i,count=1,ct=1;
	solve(0);

	while(cin>>given[0])
	{
		given[0]--;
		for(i = 1;i < 8;i++)
		{
			cin>>given[i];
			given[i]--;
		}
		printf("Case %d: %d\n", ct++, mini());
	}
	return 0;
}
