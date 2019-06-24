#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector <int> cat(11);
    cat[0] = 1;
    for(int i=1; i<=10; i++)
    {
        cat[i] = (2*(2*i-1) * cat[i-1])/ (i+1);
    }
    int n, c = 1;
    while(cin >> n){
        if(c != 1) cout << "\n"; c++;
        cout << cat[n] << "\n";
    }
    return 0;
}
