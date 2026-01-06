#include <bits/stdc++.h>
using namespace std;
/*class solution{
    public:
    int gd(int n){
        for(int i=n/2;i>=1;i--){
            if(n%i==0) return i;
        }
        return 1;
    } 
   int minSteps(int n){
    int count=0;
    while(n>1){
        int hf=gd(n);
        count+=(n/hf);
        n=hf;
    }
    return count;
   }
};*/
class solution{
    public:
 bool isprime(int n){
    if(n==1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
    int gd(int n){
         for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return n/i;
        }
        return 1;
    } 
   int minSteps(int n){
    int count=0;
    while(n>1){//O(log(n))
        if(isprime(n)){//O(sqrt(n))
            count+=n;
            break;
        }
        int hf=gd(n);//O(sqrt(n))
        count+=(n/hf);
        n=hf;
    }
    return count;
   }
};
int main() {
    solution solution;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = solution.minSteps(n);
    cout << "Minimum steps to reduce " << n << " to 1: " << result << endl;
    return 0;
}