#include <iostream>

using namespace std;

long int a[100001],b[100001],c[100001],w[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n, ca=1;
    long int inw, dew;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int ans = 0;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> w[i];
        
        inw=0;dew=0;
        for(int i=0; i<n; ++i)
        {
            b[i] = w[i]; c[i] = w[i];
            for(int j=0; j<i; j++)
            {
                if(a[i] > a[j]) b[i] = max(b[i], b[j]+w[i]);
                else if(a[i] < a[j])c[i] = max(c[i], c[j]+w[i]);
            }
            inw=max(inw,b[i]);
            dew=max(dew,c[i]);
        }
        if(inw>=dew) cout <<"Case "<<ca++<<". Increasing ("<<inw<<"). Decreasing ("<<dew<<").\n";
        else cout <<"Case "<<ca++<<". Decreasing ("<<dew<<"). Increasing ("<<inw<<").\n";
    }
}
