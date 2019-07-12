#include<bits/stdc++.h>
using namespace std;

vector<int> v;
void pre()
{
    for(int i=1;i<=1000;i++)
    {
        int sum=0;

        for(int j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                sum=sum+j;
            }
        }
        v.push_back(sum);
    }
}

int main()
{
    pre();
    int n,q=1;
    while(cin>>n && n)
    {
        int s=0,p;

        for(int i=v.size();i>=0;i--)
        {
            if(v[i]==n)
            {
                s=1;
                p=i+1;
                break;
            }
        }
        if(s==1) printf("Case %d: %d\n",q,p);
        else printf("Case %d: %d\n",q,-1);

        q++;
    }
    return 0;
}
