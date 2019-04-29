#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long int a=1, b=1, px, py, s, c, op, h;
	while(true)
	{
		cin>>a>>b;
		if(a+b==0)break;
		op=ceil(exp((double)(log(b)/2.0)));
		if(op%2==0){op++;}
		
		s=op*op;
		px=(op-1)/2+a/2+1;
		py=(op-1)/2+a/2+1;
		if(px>a)
		{
			px--;py--;s=(op-2)*(op-2);op-=2;
		}
		//long long int s0=s;
		//cout<<s0<<"\n";
		while(true)
		{
			h=s-b;
			if(h>(op-1)){py-=(op-1);s-=(op-1);}
			else{py-=h;s-=h;break;}
			h=s-b;
			if(h>(op-1)){px-=(op-1);s-=(op-1);}
			else{px-=(h);s-=h;break;}
			h=s-b;
			if(h>(op-1)){py+=(op-1);s-=(op-1);}
			else{py+=(h);s-=h;break;}
			h=s-b;
			if(h>(op-2)){px+=(op-2);s-=(op-2);}
			else{px+=(h);s-=h;break;}
			h=s-b;
			if(h>(op-2)){py-=(op-2);s-=(op-2);}
			else{py-=(h);s-=h;break;}
			h=s-b;
			if(h>(op-3)){px-=(op-3);s-=(op-3);}
			else{px-=(h);s-=h;break;}
			h=s-b;
			if(h>(op-3)){py+=(op-3);s-=(op-3);}
			else{py+=(h);s-=h;break;}
			h=s-b;
			if(h>(op-4)){px+=(op-4);s-=(op-4);}
			else{px+=(h);s-=h;break;}
			h=s-b;
			if(h>(op-4)){py-=(op-4);s-=(op-4);}
			else{py-=(h);s-=h;break;}
			//cout<<s<<" "<<op<<" "<<s0<<"\n";
		}
		cout<<"Line = "<<py<<", column = "<<px<<".\n";
	}
	return 0;
}
