#include<bits/stdc++.h>
#define sz 1003
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
vector<int>out;
int n,e;
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
        par[y]=x;
    else par[x]=y;
}
void mst(void)
{
    int i,j,x,y;
    for(i=0; i<e; i++)
    {
        x=set_find(vec[i].f);
        y=set_find(vec[i].t);

        if(x!=y)
            link(x,y);
        else
            out.push_back(vec[i].c);
    }
    return;
}
void ini(void)
{
    for(int i=0; i<=n; i++)
        par[i]=i;
}
void clearall(void)
{
    vec.clear();
    out.clear();

}
int main()
{
    // freopen("in.txt","r",stdin);
    int t,i,j,f,c;
    while(scanf("%d %d",&n,&e)==2)
    {

        if(n==0 && e==0)break;
        ini();
        clearall();
        for(j=0; j<e; j++)
        {
            scanf("%d %d %d",&f,&t,&c);
            vec.push_back(edge(f,t,c));
        }
        sort(vec.begin(),vec.end(),comp);
        mst();
        if(out.size()==0)
            printf("forest\n");
        else
        {
            sort(out.begin(),out.end());
            printf("%d",out[0]);
            for(i=1; i<out.size(); i++)
                printf(" %d",out[i]);
            printf("\n");
        }
    }
    return 0;
}

