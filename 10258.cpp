#include<bits/stdc++.h>

using namespace std;

struct Test 
{ 
   int x, y, z; 
}; 

bool comparator(Test a,Test b)
{
	if(a.y>b.y)
	{
		return true;
	}
	else if(a.y==b.y && a.z<b.z)
	{
		return true;
	}
	else if(a.y==b.y && a.z==b.z && a.x<b.x)
	{
		return true;
	}
	return false;
}

int main()
{
	int t,c,p,time,k=0;
	char ch;
	int tim[101],que[101];
	cin>>t;
	
	string st,sp;
	getline(cin,sp);
	while(t--)
	{
		vector<Test>v; 
		int comp[101][10];
		for(int i=0;i<=100;i++)
		{
			tim[i]=0;que[i]=0;
			for(int j=0;j<10;j++)
			{
				comp[i][j]=0;
			}
		}
		cout<<k++<<"\n";
		while(getline(cin,st))
		{
			
			stringstream ss(st);
			ss>>c>>p>>time>>ch;
			
			if(ch=='C' && comp[c][p]!=1)
			{
				tim[c]+=time;
				que[c]+=1;
				comp[c][p]=1;
			}
			else if(ch=='I' && comp[c][p]!=1)
			{
				tim[c]+=20;
			}
		}
		for(int i=0;i<101;i++)
		{
			if(tim[i]!=0)
			{
				if(que[i]==0)tim[i]=0;
				v.push_back({i,que[i],tim[i]});
			}
		}
		
		sort(v.begin(),v.end(),comparator);
		
		for(int i=0;i<v.size();i++)
		{
			cout<<v[i].x<<" "<<v[i].y<<" "<<v[i].z<<"\n";
		}
		
		cout<<"\n";
	}
	return 0;
}
