#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	string st;
	while(true)
	{
		cin>>st;
		if(st=="#"){return 0;}
		bool val = next_permutation(st.begin(), st.end()); 
	        if (val == false)cout << "No Successor\n"; 
	        else cout<<st<<endl; 
	}
	return 0;
}
