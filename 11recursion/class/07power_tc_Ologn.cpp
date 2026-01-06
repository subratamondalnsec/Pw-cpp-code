#include <bits/stdc++.h>
using namespace std;
int power(int a,int b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0){
        int ans=power(a,b/2);
        return ans*ans;
    } 
     if(b%2!=0){
        //return a*power(a,b-1);
         int ans=power(a,b/2);
         return ans*ans*a;
    } 
}
int main(){
    int a,b;
    cout<<"enter the base number :";
    cin>> a;
    cout<<"enter the power number :";
    cin>> b;
    cout<<"The answer is:"<<power(a,b);
}