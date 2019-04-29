#include<iostream>
#include<set>
#include<iterator>

using namespace std;

int main()
{
	long int l,r,s,b,d;
	
	cin>>s>>b;
	while(s!=0 && b!=0)
	{
		set<int>se;
		set<int>::iterator it, it1, it2;
		for(long int i=1;i<=s;i++)
		{
			se.insert(i);
		}
		for(long int j=0;j<b;j++)
		{
			cin>>l>>r;
			it1=se.upper_bound(r);
			it2=se.find(l);
			if(!se.empty() && it2!=se.begin())
			{
				it2--;
				cout<<*it2<<" ";
			}
			else
			{
				cout<<"* ";
			}
			if(it1!=se.end())
			{
				d=*it1;
				se.erase(se.find(l),it1);	
			}
			else
			{
				d=-1;
				se.erase(se.find(l),se.end());
			}
			//it2=se.lower_bound(l);
			//cout<<*it2<<"===";
			//if(!se.empty() && *it2<l){}
			//else{cout<<"* ";}
			
			if(d!=-1){cout<<*it1<<"\n";}
			else{cout<<"*\n";}
		}
		cout<<"-\n";
		cin>>s>>b;
	}
	return 0;
}
