#include<bits/stdc++.h>
#define sz 103
#define inf 1<<29
using namespace std;

struct edge
{
    int f,t,c;
    edge(int a,int b,int co)
    {
        f=a;
        t=b;
        c=co;
    }
};

vector<edge>vec;
int n,e,ans2,edgetaken[sz],etl;
int comp(edge a,edge b)
{
    return a.c<b.c;
}
int par[sz];
int set_find(int a)
{
    if(a==par[a])
        return a;
    return(par[a]=set_find(par[a]));
}
void link(int x,int y)
{
    if(x>y)
        par[x]=y;
    else par[y]=x;
}
int  mst(void)
{
    int i=0,j,x,y,sum=0,cnt=0;
    etl=0;
    sort(vec.begin(),vec.end(),comp);
    for(i=0; i<e && cnt<n-1; i++)
    {
        x=set_find(vec[i].f);
        y=set_find(vec[i].t);

        if(x!=y)
        {
            link(x,y);
            sum+=vec[i].c;
            edgetaken[etl++]=i;
            cnt++;
        }
    }
    return sum;
}
void ini(void)
{
    for(int i=1; i<=n; i++)
        par[i]=i;
}

int main()
{
//   freopen("in.txt","r",stdin);

    int t,i,j,f,c,tst,cs,cnt,ans1,an2,x,y,miin;
    scanf("%d",&tst);
    for(cs=1; cs<=tst; cs++)
    {
        scanf("%d %d",&n,&e);
        ini();
        vec.clear();
        memset(edgetaken,0,sizeof edgetaken);
        for(j=0; j<e; j++)
        {
            scanf("%d %d %d",&f,&t,&c);
            vec.push_back(edge(f,t,c));
        }

        ans1=mst();

        //2nd mst
        miin= inf;
        for(i=0; i<etl; i++)
        {
            ini();
            cnt=0;
            ans2=0;
            for(j=0; j<e && cnt<n-1; j++)
            {
                //     printf("i %d j %d\n",i,j);
                if(edgetaken[i]!=j)
                {
                    x=set_find(vec[j].f);
                    y=set_find(vec[j].t);
                    //       printf("f %d t %d c %d\n",vec[j].f,vec[j].t,vec[j].c);
                    if(x!=y)
                    {
                        cnt++;
                        link(x,y);
                        ans2+=vec[j].c;
                    }
                }
            }
            //   printf("ans %d\n",ans2);
            if(cnt==n-1 && miin>ans2)
                miin=ans2;
        }
        printf("%d %d\n",ans1,miin);
    }
    return 0;
}

