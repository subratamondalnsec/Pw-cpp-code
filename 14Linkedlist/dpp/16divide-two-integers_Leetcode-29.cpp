#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        else if(divisor==dividend) return 1;
        else if(divisor==1) return dividend;
        else if(divisor==-1) return -dividend;
        else if (divisor==INT_MIN) return 0;
        else if( (long long)divisor  + (long long) dividend==0) return -1;
        bool flag1=false;
        bool flag2=false;
        if(dividend<0) flag1=true; 
        if(divisor<0)  flag2=true;
        if(dividend>0) dividend=-dividend;
        if(divisor<0) divisor=-divisor;
        int q=-1;
        while(dividend<=0){
            dividend+=divisor;
            q++;
        }
        if(flag1==flag2) return q;
        else return -q;
    }
};

int main() {
    Solution solution;
    int dividend, divisor;

    std::cout << "Enter dividend: ";
    std::cin >> dividend;
    std::cout << "Enter divisor: ";
    std::cin >> divisor;

    int result = solution.divide(dividend, divisor);
    std::cout << "Result: " << result << std::endl;

    return 0;
}