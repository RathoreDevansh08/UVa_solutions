#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

#define Qwerty "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./ ~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?"
#define Dvorak "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg' ~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\""

char keymap[100];

void preProcess() 
{
    int i, n=strlen(Qwerty);
    fr(i,0,n-1) keymap[ Qwerty[i] ] = Dvorak[i];
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int i,len;
    string st;
    
    preProcess();
    while (getline(cin, st)) 
    {
        len=st.length();
        fr(i,0,len-1) cout<<keymap[st[i]];
        cout<<"\n";
    }
}
