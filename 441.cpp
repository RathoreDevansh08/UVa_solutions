#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,x,k=0;
	while(true)
	{
		cin>>n;
		if(k==0)k++;
		else if (n) cout<<"\n";
		if(!n)return 0;
		
		vector<int>a(n);
		for(int i=0;i<n;i++){cin>>x;a[i]=x;}
		
		for(int i0=0;i0<n-5;i0++)
		{
			for(int i1=i0+1;i1<n-4;i1++)
			{
				for(int i2=i1+1;i2<n-3;i2++)
				{
					for(int i3=i2+1;i3<n-2;i3++)
					{
						for(int i4=i3+1;i4<n-1;i4++)
						{
							for(int i5=i4+1;i5<n;i5++)
							{
								cout<<a[i0]<<" "<<a[i1]<<" "<<a[i2]<<" "<<a[i3]<<" "<<a[i4]<<" "<<a[i5]<<"\n";
							}
						}
					}	
				}
			}
		}
	}
	return 0;
}
