#include<bits/stdc++.h>
using namespace std;
string decimal_to_binary(int nums){
    string result="";
    while(nums>0){
        if(nums%2==0){
            result='0'+result;
        }
        else{
              result='1'+result;
        }
        nums/=2;//nums=nums>>1;
    }
    return result;
}
int maxpowerOftwo(int x){
    int temp;
    while(x!=0){
        temp=x;
        x=x & (x-1);
    }
    return temp;
}
int main(){
    int m=29;
    cout<<decimal_to_binary(m)<<endl;
    int n=maxpowerOftwo(m);
    n=(n<<1)-1;
    n=n^m;
    cout<<decimal_to_binary(n);
}
