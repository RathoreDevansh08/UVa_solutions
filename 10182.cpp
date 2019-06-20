#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int k=0,ring=1;
        while(ring<n){
            k++;
            ring+=6*k;
        }
        int x=k,y=0;
        while(ring!=n){
            while(ring!=n&&y+k!=0)
                y--,ring--;
            while(ring!=n&&x!=0)
                x--,ring--;
            while(ring!=n&&y!=0)
                x--,y++,ring--;
            while(ring!=n&&y!=k)
                y++,ring--;
            while(ring!=n&&x!=0)
                x++,ring--;
            while(ring!=n&&x!=k)
                x++,y--,ring--;
        }
        cout<<x<<' '<<y<<endl;
    }
}
