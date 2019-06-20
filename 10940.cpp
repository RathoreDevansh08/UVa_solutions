#include<stdio.h>
int main()
{
    int x,n,s;
    while(scanf("%d",&n)==1)
    {
    if(n==0)
    break;
     x=1;
    while(x<=n)
      {
      x=x*2;
      s=x%n;
      }
      printf("%d\n",n-s);
    }
    
}
