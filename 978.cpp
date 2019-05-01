#include<iostream>
#include<set>
#include<iterator>

using namespace std;

int main()
{
	int n,b,sg,sb,x;
	cin>>n;
	
	while(n--)
	{
		cin>>b>>sg>>sb;
		multiset<int,greater<int>>gr,bl;
		multiset<int,greater<int>>::iterator G,B;
		for(int i=0;i<sg;i++){cin>>x;gr.insert(x);}
		for(int i=0;i<sb;i++){cin>>x;bl.insert(x);}
		
		if(b>min(sg,sb))b=min(sg,sb);
		while(gr.size()!=0 && bl.size()!=0)
		{
			int yg=gr.size(),yb=bl.size();
			b=min(b,min(yg,yb));
			int j=0;
			multiset<int,greater<int>>g0,b0;
			while(j!=b)
			{
				B=bl.begin();G=gr.begin();
				int m=abs(*B-*G);
				if(*B>*G)
				{
					b0.insert(m);
				}
				else if(*G>*B)
				{
					g0.insert(m);
				}
				bl.erase(B);gr.erase(G);
				j++;
			}
			if(b0.size()!=0)bl.insert(b0.begin(),b0.end());
			if(g0.size()!=0)gr.insert(g0.begin(),g0.end());
			//cout<<b<<bl.size()<<gr.size()<<endl;
		}
		if(gr.size()==0 && bl.size()==0)
		{
			if(n)cout<<"green and blue died\n\n";
		}
		else if(gr.size()==0)
		{
			cout<<"blue wins\n";
			for(B=bl.begin();B!=bl.end();++B)cout<<*B<<"\n";
			if(n)cout<<"\n";
		}
		else
		{
			cout<<"green wins\n";
			for(G=gr.begin();G!=gr.end();++G)cout<<*G<<"\n";
			if(n)cout<<"\n";
		}
	}
	return 0;
}
