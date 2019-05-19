/*Best Solution==>>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[100000], dp[100000], dpi[100000], n = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  	while (cin >> arr[n++]);
  	int ans = 0;
  	for (int i = 0; i < n; i++) {
    	int c  = lower_bound(dp, dp+ans+1, arr[i]) - dp;
    	dp[c] = arr[i];
    	dpi[i] = c;
    	ans = max(c, ans);
  	}
	vector<ll> a;
  	for (int i = n; i >= 0; i--)
    	if (dpi[i] == ans) {
      		a.push_back(arr[i]);
      		ans--;
   		}

  	cout << a.size() << endl << '-' << endl;
 	reverse(a.begin(), a.end());
  	for (int i = 0; i < a.size(); i++)
    	cout << a[i] << "\n";
}
*/

#include<algorithm>
#include<cstdio>
 
using namespace std;
 
int A[1000000], M[1000000], M_id[1000000], P[1000000];
 
void print(int end) {
    if(end < 0) return;
    print(P[end]);
    printf("%d\n", A[end]);
}
 
int main() {
    int L = 0, L_end = 0;
    for(int i = 0;; i++) {
        if(scanf("%d", &A[i]) != 1) break;
 
        int pos = lower_bound(M, M + L, A[i]) - M;
        M[pos] = A[i];
        M_id[pos] = i;
        P[i] = pos > 0? M_id[pos - 1] : -1;
        if(pos == L) {
            L++;
            L_end = i;
        }
    }
    printf("%d\n-\n", L);
    print(L_end);
}
