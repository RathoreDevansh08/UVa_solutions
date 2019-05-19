#include <iostream>

using namespace std;

int a[2001],b[2001],c[2001],d[2001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int ans = 0;
        for(int i=0; i<n; i++) cin >> a[i];
        
        for(int i=n-1; i>=0; i--)
        {
            b[i] = 1; c[i] = 1;
            for(int j=i+1; j<n; j++)
            {
                if(a[i] < a[j]) b[i] = max(b[i], b[j]+1);
                else c[i] = max(c[i], c[j]+1);
            }
            ans = max(ans, b[i]+c[i]-1);
        }
        cout << ans << "\n";
    }
}
