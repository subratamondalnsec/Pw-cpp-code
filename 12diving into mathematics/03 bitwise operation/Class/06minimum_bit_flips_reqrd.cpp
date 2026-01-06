#include<bits/stdc++.h>
using namespace std;
int count_set_bits(int n){
    int count=0;
    while(n>0){
        count++;
        n=(n & (n-1));
    }
    return count;
}
int main(){
    int x=23;
    int y=31;
     cout<<count_set_bits((x^y));

}