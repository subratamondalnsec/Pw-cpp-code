#include <bits/stdc++.h>
using namespace std;
     bool isPerfectSquare(int n){
        int root=sqrt(n);
        if((root*root)==n) return true;
        else return false;
     }
      bool judgeSquareSum(int c) {
        int x=0;
        int y=c;
        while(x<=y){
            if(isPerfectSquare(x) && isPerfectSquare(y)) return true;
            else if(!isPerfectSquare(y)) { 
                y = (int)sqrt(y)*(int)sqrt(y); 
                x = c-y;
            }
        else{ // x is not perfect
        x = ((int)sqrt(x) + 1)*((int)sqrt(x) + 1);
        y = c-x;
            }
        }
        return false;
    };


        bool judgeSquareSum(int c) {
            long long l=0,h=sqrt(c);
            while(l<=h){
                if(l*l+h*h==c) return true;
                else if(l*l+h*h>c) h--;
                else l++;
            }
            return false;
        }

    int main() {
    int testValue = 41; // Example test value
    bool result = judgeSquareSum(testValue);
    cout << "The result for " << testValue << " is " << (result ? "true" : "false") << endl;
    return 0;
}