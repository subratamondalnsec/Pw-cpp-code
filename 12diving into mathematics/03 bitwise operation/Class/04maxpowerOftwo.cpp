#include<bits/stdc++.h>
using namespace std;
int maxpowerOftwo(int x){
    int temp;
    while(x!=0){
        temp=x;
        x=x & (x-1);
    }
    return temp;
}
int maxpowerOftwo2(int x){
     x=x |(x>>1);
     x=x |(x>>2);
     x=x |(x>>4);
     x=x |(x>>8);
     x=x |(x>>16);
    return (x+1)>>1;
}

int main(){
     cout<< maxpowerOftwo(100)<<endl;
      cout<< maxpowerOftwo2(100);
}