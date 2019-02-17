#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T, K, M, l;
	map <char, double> mp;
	map <char, double>::iterator it;
	char c;
	string line;
	double v, total;

	scanf("%d", &T);
	while(T--)
	{
		total = 0;
		scanf("%d", &K);
		for(int i = 0; i < K; i++){
			cin >> c >> v;
			mp[c] = v;
		}
		scanf("%d", &M);
		cin.ignore();
		for(int i = 0; i < M; i++){
			line = "";
			getline(cin, line);
			l = line.size();
			for(int j = 0; j < l; j++){
				it = mp.find(line[j]);
				if(it != mp.end())
					total += it->second;
			}			
		}
		total /= 100;
		printf("%0.2lf$\n", total);
		mp.clear();
	}
	return 0;
}
