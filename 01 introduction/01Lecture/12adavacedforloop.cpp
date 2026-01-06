#include<iostream>
using namespace std;
unsigned long long factorial(long long n){
    unsigned long long result=1;
    for(int i=2;i<n;++i){
        result*=i;
    }
    return result;
}
int main(){
    long long n;
    cin>>n;
    cout<<factorial(n)<<endl;
}