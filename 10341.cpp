#include<bits/stdc++.h>

using namespace std;

int p,q,r,s,t,u;
double x,f,fa,fb;

double func(double x)
{
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

void bisection(double a,double b)
{
	double err=1.0;
	if(func(a)==0) {cout<<"0.0000\n";return;}
	else if(func(b)==0) {cout<<"1.0000\n";return;}
	if(func(a)*func(b)<0)
	{
		while(err>=0.0000001)
		{
			x=(a+b)/2;
			f=func(x);fa=func(a);fb=func(b);
			
			if(f==0) {printf("%0.4lf\n",x);return;}
			if(f*(fa)>0) a=x;
			else b=x;
			err=abs(b-a);
		}
		printf("%0.4lf\n",x);
		return;
	}
	else cout<<"No solution\n";
}

int main()
{
	while(cin>>p>>q>>r>>s>>t>>u) bisection(0.0,1.0);
	return 0;
}
