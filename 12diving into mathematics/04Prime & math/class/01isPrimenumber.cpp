#include <bits/stdc++.h>
using namespace std;
bool isprime(int n){
    if(n==1) return false;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    isprime(10)?cout<<"it is prime":cout<<"it is not prime";

}