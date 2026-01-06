#include <bits/stdc++.h>
using namespace std;
int minproductsubset(vector<int>& arr){
    int neg=0,pos=0,zero=0, prod_pos=1,prod_neg=1,mn=INT_MAX,largest_neg=INT_MIN;
    for(int i: arr){
        if(i>0){
            pos++;
            prod_pos*=i;
        } 
        if(i<0){
            neg++;
            prod_neg*=i;
            largest_neg=max(largest_neg,i);
        } 
        if(i==0) zero++;
        mn=min(mn,i);
    }
    if(neg==0){
        if(zero>0) return 0;
        else return mn;
    }
    else if(neg%2!=0) return prod_pos*prod_neg;
    else if(neg%2==0){
        return ((prod_neg/largest_neg)*prod_pos);
    }
}
int main(){
    vector<int> arr={2,1,4};
    cout<<minproductsubset(arr);
}