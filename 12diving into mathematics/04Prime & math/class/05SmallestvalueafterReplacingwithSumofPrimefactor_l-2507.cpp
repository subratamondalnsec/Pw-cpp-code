#include <bits/stdc++.h>
using namespace std;
class solution{
    public:
 bool isprime(int n){
    if(n==1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
int smallestValue(int n){
    if(isprime(n)) return n;
    int sum=0;
    for(int i=1;i<sqrt(n);i++){//O(sqrt(n))
            if(n%i==0 && isprime(i)) {
                int m=n;
                while(m%i==0){//O(logn)
                    sum+=i;
                    m/=i;
                }
            }
        }
     for(int i=sqrt(n);i>1;i--){
            if(n%i==0&& isprime(n/i)){
                int m=n;
                while(m%(n/i)==0){
                    sum+=(n/i);
                    m/=(n/i);
                }
            }
        }
        if(sum==n) return n;
        return smallestValue(sum);
}
};
int main() {
    solution solution;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Smallest value: " << solution.smallestValue(n) << std::endl;
    return 0;
}