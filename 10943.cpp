#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    int dp[205][205] = {0};
    dp[0][0] = 1;
    for(int i=1; i<=200; i++)
    {
        dp[i][0] = 1;
        for(int j=1; j<=i; j++)
        {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%1000000;
        }
    }
    while(cin >> n >> k, n||k) cout << dp[n+k-1][k-1] << "\n";
    return 0;
}
