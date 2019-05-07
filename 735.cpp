#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int>c(181,0),p(181,0);
	set<int>f;
	
	for(int i=0;i<=20;i++)
	{
		f.insert(i);f.insert(2*i);f.insert(3*i);
	}
	
	map<vector<int>,int>mp;
	
	for(int i=0;i<=60;i++)
		{
			if(f.find(i)==f.end())continue;
			for(int j=0;j<=60;j++)
			{
				if(f.find(j)==f.end())continue;
				for(int k=0;k<=60;k++)
				{ 
					if(f.find(k)==f.end())continue;
					else
					{
						//if(i+j+k==68)cout<<i<<" "<<j<<" "<<k<<" \n";
						p[i+k+j]++;
						vector<int>s;
						s.push_back(i);s.push_back(j);s.push_back(k);
						sort(s.begin(),s.end());
						if(mp.find(s)==mp.end())
						{
							c[i+j+k]++;
							mp[s]=1;
						}
					}
				}
			}
		}
	
	int n;
	while(true)
	{
		cin>>n;
		if(n<=0)
		{
			cout<<"END OF OUTPUT";	
			return 0;
		}
		
		if(n>180)
		{
			cout<<"THE SCORE OF "<<n<<" CANNOT BE MADE WITH THREE DARTS.\n";
			cout<<"**********************************************************************\n";
		}
		else
		{
			if(c[n]==0)
			{
				cout<<"THE SCORE OF "<<n<<" CANNOT BE MADE WITH THREE DARTS.\n";
				cout<<"**********************************************************************\n";
				continue;
			}
			cout<<"NUMBER OF COMBINATIONS THAT SCORES "<<n<<" IS "<<c[n]<<".\n";
			cout<<"NUMBER OF PERMUTATIONS THAT SCORES "<<n<<" IS "<<p[n]<<".\n";		
			cout<<"**********************************************************************\n";		
		}
	}
	return 0;
}

