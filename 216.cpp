#include<bits/stdc++.h>

using namespace std;

#define inf 10000000
float l,graph[12][12];
int n;
vector<int>v;

float tsp()
{
	vector<int> vertex; 
	for (int i = 0; i < n; i++) vertex.push_back(i); 

	float min_path = 1000000000.00; 
	do 
	{  
	  float current_pathweight = 0.0;int k = 0; 
	  for (int i = 1; i < n; i++) 
	  { 
		current_pathweight += graph[vertex[k]][vertex[i]]; 
		k = i; 
	  } 
	  current_pathweight += (float)(16.0*(n-1));  
	  if(min_path>current_pathweight)
	  {
	  	min_path=current_pathweight;
	  	v=vertex;
	  } 
	   
	}while(next_permutation(vertex.begin(), vertex.end())); 

	return min_path; 
}

int main()
{
	int c=1;
	while(cin>>n && n)
	{
		cout<<"**********************************************************\n";
		cout<<"Network #"<<c++<<"\n";
		
		int x[n],y[n];
		for(int i=0;i<n;i++) cin>>x[i]>>y[i];
		
		for(int i=0;i<n;i++)
			for(int j=0;j<=i;j++)
				graph[i][j]=graph[j][i]=(float)pow((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]),0.5);
				
		l=tsp();
		for(int i=0;i<n-1;i++)
		{
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %0.2f feet.\n",x[v[i]],y[v[i]],x[v[i+1]],y[v[i+1]],graph[v[i]][v[i+1]]+16.00);
		}
		printf("Number of feet of cable required is %0.2f.\n",l);
	}
	
	return 0;
}
