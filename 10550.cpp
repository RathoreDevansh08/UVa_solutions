#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int st, first, second, third;
    scanf("%d %d %d %d", &st, &first, &second, &third);
    
    while(st || first || second || third)
    {
        printf("%d\n",1080+((st-first+40)%40+(second-first+40)%40+(second-third+40)%40)*9);
        scanf("%d %d %d %d",&st,&first,&second,&third);
    }
    return 0;
}
