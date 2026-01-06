#include<bits/stdc++.h>
using namespace std;
int smallest_power_two(int n){
    int temp=0;
    while(n!=0){
        temp=n;
        n=(n & (n-1));
    }
    return temp;
}
int main(){
    int n;
    cout<<"Enter the integer : ";
    cin>>n;
    int s=smallest_power_two(n);
    cout<<"Smallest power of two that is set in that integer is :"<<s;
    int l=s<<1;
    cout<<"\nLargest power of two that is set in that integer is :"<<l;
}