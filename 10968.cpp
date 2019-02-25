#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void addEdge(vector<int>adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 

int BFS(int v,vector<int>adj[],int count[],int s) 
{ 
    int vis[v],dis[v],d=0,r=0; 
    for(int i=0;i<v;i++){vis[i]=0;dis[i]=-1;} 
  
    queue<int>Q; 
  
    vis[s]=1;
    dis[s]=0; 
    Q.push(s); 

    while(!Q.empty() && !r) 
    { 
        s = Q.front();  
        Q.pop(); 
 	int n=adj[s].size();
        for(int i=0;i<n;i++) 
        {
            d=adj[s][i];
            if(count[d]<=2)continue;
            if(!vis[d]) 
            { 
                vis[d] = 1; 
                dis[d]=dis[s]+1;
                if(count[d]%2==1)
                {
                	r=1;break;
                }
                Q.push(d); 
            } 
        } 
    }
    if(r){return dis[d];}
    else return -1; 
}

int main()
{
	int v,e,a,b;
	string st;
	while(true)
	{
		cin>>v>>e;
		
		if(v==0 && e==0)return 0;
		
		vector<int>adj[v];
		int ve[2],k=0,f=1;
		int count[v],min=0;
		
		for(int i=0;i<v;i++)count[i]=0;
		for(int i=0;i<e;i++)
		{
			cin>>a>>b;
			addEdge(adj,a-1,b-1);
			count[a-1]++;count[b-1]++;
		}

		for(int i=0;i<v;i++)
		{
			if(count[i]%2!=0)
			{
				ve[k]=i;k++;
				if(count[i]==1)f=0;
			}
			if(count[i]==0)f=0;
		}
		
		if(f==1)
		{
			int w;
			if(k==0)w=0;
			else w=BFS(v,adj,count,ve[0]);
				
			if(w==-1)cout<<"Poor Koorosh\n";
			else cout<<w<<"\n";
		}
		else
		{
			cout<<"Poor Koorosh\n";
		}
		getline(cin,st);
	}
	return 0;
}
