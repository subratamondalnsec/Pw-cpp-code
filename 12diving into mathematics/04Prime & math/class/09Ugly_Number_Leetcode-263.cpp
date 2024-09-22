#include <bits/stdc++.h>
using namespace std;
class solution{
    public:
       bool isUgly(int n){
        if(n==0) return false;
        while(n%2==0) n/=2;
        while(n%3==0) n/=3;
        while(n%5==0) n/=5;
        return (n==1);//if(n==1) return true; else false; its equal
       }
};
int main() {
    solution solution;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    bool result = solution.isUgly(n);
    cout << n << (result ? " is " : " is not ") << "an ugly number." << endl;
    return 0;
}