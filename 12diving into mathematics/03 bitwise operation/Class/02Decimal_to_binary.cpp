#include <bits/stdc++.h>
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
int main(){
cout<<decimal_to_binary(18);
}