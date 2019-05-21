#include<bits/stdc++.h>

using namespace std;

#define inf 10000000
int graph[12][12];
int t,n,wx,wy,sx,sy;

int tsp(int s)
{
	vector<int> vertex; 
	for (int i = 1; i < n; i++) vertex.push_back(i); 

	int min_path = 1000000000; 
	do 
	{  
	  int current_pathweight = 0, k = s; 
	  for (int i = 0; i < vertex.size(); i++) 
	  { 
		current_pathweight += graph[k][vertex[i]]; 
		k = vertex[i]; 
	  } 
	  current_pathweight += graph[k][s];  
	  min_path = min(min_path, current_pathweight); 
	   
	}while(next_permutation(vertex.begin(), vertex.end())); 

	return min_path; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		cin>>wx>>wy;
		cin>>sx>>sy;
		cin>>n;n++;
		int x[n],y[n];
		x[0]=sx;y[0]=sy;
		for(int i=1;i<n;i++) cin>>x[i]>>y[i];
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				graph[i][j]=graph[j][i]=abs(x[i]-x[j])+abs(y[i]-y[j]);
				
		cout<<"The shortest path has length "<<tsp(0)<<"\n";
	}
	
	return 0;
}
