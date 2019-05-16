#include <iostream>

using namespace std;

bool isSmall[110],hit[110];
int pos[110];

int dist(int n)
{
    int mn=pos[0];
    for(int i=0;i<n;i++)
    {
        hit[i]=true;
        if(!isSmall[i+1])
        {
            mn=max(mn,pos[i+1]-pos[i]);
        }
        else
        {
            mn=max(mn,pos[i+2]-pos[i]);
            ++i;
        }
    }
    
    for(int i=n;i>0;--i)
    {
        if(!hit[i-1] || !isSmall[i-1])
        {
            mn=max(mn,pos[i]-pos[i-1]);
        }
        else
        {
            mn=max(mn,pos[i]-pos[i-2]);
            --i;
        }
    }
    return mn;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	char a,b;
	int t,n,d,c=1;
	cin>>t;
    
	while(t--)
	{
		cin>>n>>d;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b>>pos[i];
			isSmall[i]=(a=='S');
			hit[i]=false;
		}
	  
	  isSmall[n]=false;
	  pos[n]=d;
	  hit[n]=false;
	  
	  cout<<"Case "<<c++<<": "<<dist(n)<<"\n";
	}
	return 0;
}
