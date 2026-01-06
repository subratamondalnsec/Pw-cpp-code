#include <bits/stdc++.h>
using namespace std;
class solution{
public:
   bool checkPerfectNumber(int n){
    int sum=0;
    for(int i=1;i<sqrt(n);i++){
        if(n%i==0) sum += i;
    }
    for(int i=sqrt(n);i>1;i--){
        if(n%i==0) sum += n/i;
    }
    return (sum==n);
}
};
int main() {
    solution solution;
    int n;
   cout << "Enter a number: ";
   cin >> n;
    if (solution.checkPerfectNumber(n)) {
        cout << n << " is a perfect number." <<endl;
    } else {
        cout << n << " is not a perfect number." <<endl;
    }
    return 0;
}