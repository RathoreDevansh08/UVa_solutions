#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int f,r,x;
	while(true)
	{
		cin>>f;
		if(!f)return 0;
		cin>>r;
		
		int af[f],k=0;
		vector<float>t(f*r);
		for(int i=0;i<f;i++)cin>>af[i];
		for(int i=0;i<r;i++)
		{
			cin>>x;
			for(int j=0;j<f;j++)
			{
				t[k++]=(float)x/af[j];
			}
		}

		sort(t.begin(),t.end());
		float m=-1.00;
		for(int i=0;i<f*r-1;i++)
		{
			m=max(m,t[i+1]/t[i]);
		}
		printf("%0.2f\n",m);
		
	}
	return 0;
}
