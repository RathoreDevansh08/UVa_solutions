#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  double amount;
  while(scanf("%d",&n) && n!=0){
    vector<double> money;
    double amount,total=0,respPos=0,respNeg=0;
    for (int i = 0; i < n; ++i)
    {
      scanf("%lf",&amount);
      total += amount;
      money.push_back(amount);
    }
    total /= n;
    for (int i = 0; i < n; ++i)
    {
      double dif =(double) (long) ((money[i]-total) * 100.0) / 100.0;
      if(dif>0)
        respPos+=dif;
      else
        respNeg+=dif;
    }
    double resp = (-respNeg > respPos) ? -respNeg : respPos;
    resp = (resp<0)?-resp:resp;
    printf("$%.2lf\n",resp);
  }

 return 0;  
}
