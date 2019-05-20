#include <iostream>

using namespace std;

unsigned long long ways[30001];
int coins[] = {1, 5, 10, 25, 50};
void preprocess()
{
	ways[0] = 1;
	for (int c = 0; c < 5; ++c)
	{
		for (int i = coins[c]; i < 30001; ++i)
		{
			ways[i] += ways[i - coins[c]];
		}
	}
}

int main()
{
	preprocess();
	int cents;
	while (cin >> cents)
	{
	      if (ways[cents] == 1) cout << "There is only 1 way to produce " << cents << " cents change.\n";
	      else cout << "There are " << ways[cents] << " ways to produce " << cents << " cents change.\n";
	}
	return 0;
}
