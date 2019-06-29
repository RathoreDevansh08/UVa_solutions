#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


const int maxn = 155;
string F[maxn] , num1 , num2 , sum , tsum;
vector<int> ans;


string add(string n1 , string n2){
    int len1 = n1.length() , len2 = n2.length() , carry = 0;
    string result;
    for(int i = len1-1 , j = len2-1; i >= 0 || j >= 0; i-- , j--){
        int sum = carry;
        if(i >= 0) sum += n1[i]-'0';
        if(j >= 0) sum += n2[j]-'0';
        carry = sum/10;
        sum = sum%10;
        result.push_back(char('0'+sum));
    }
    if(carry) result.push_back(char('0'+carry));
    reverse(result.begin() , result.end());
    return result;
}


void Fibonacci(){
    F[0] = "1";
    F[1] = "2";
    for(int i = 2; i < maxn; i++){
        F[i] = add(F[i-1] , F[i-2]);
    }
}


string get_sum(string num){
    int len = num.length();
    string tem = "0";
    for(int i = 0; i < len; i++){
        if(num[len-1-i] == '1') tem = add(tem , F[i]);
    }
    return tem;
}


void ini(){
    sum = "0";
    tsum = "0";
    ans.clear();
}


bool is_larger(string n1 , string n2){
    int len1 = n1.length() , len2 = n2.length();
    if(len1 > len2) return true;
    if(len1 < len2) return false;
    for(int i = 0; i < len1; i++){
        if(n1[i]-'0' > n2[i]-'0') return true;
        if(n1[i]-'0' < n2[i]-'0') return false;
    }
    return false;
}


int Binary_search(int l , int r){
    while(l < r){
        int mid = (l+r)/2;
        if(is_larger(add(tsum , F[mid]) , sum)){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    r--;
    tsum = add(tsum , F[r]);
    return r;
}


void computing(){
    sum = add(get_sum(num1) , get_sum(num2));
    int l = 0 , r = 150;
    while(is_larger(sum , tsum)){
        r = Binary_search(l , r);
        ans.push_back(r);
    }
    ans.push_back(-1);
    for(int i = 0; i < ans.size()-1; i++){
        printf("1");
        for(int j = 1; j < ans[i]-ans[i+1]; j++){
            printf("0");
        }
    }
    if(ans.size() == 1) printf("0");
    printf("\n");
}

int main(){
    Fibonacci();
    //test();
    int t = 0;
    while(cin >> num1 >> num2){
        ini();
        if(t) printf("\n");
        t++;
        computing();
    }
    return 0;
}
