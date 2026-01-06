#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
    if(num==1) return true;
    long long n=(long long) num;
    long long lo=0;
    long long hi=n-1;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        long long m= (long long )mid*mid;
        if(m==n) return true;
        else if(m<n) lo=mid +1;
        else hi = mid-1;
    }
    return false;
    }
};

int main() {
    Solution solution;
    int testNum;
    
    std::cout << "Enter a number to check if it's a perfect square: ";
    std::cin >> testNum;

    if (solution.isPerfectSquare(testNum)) {
        std::cout << testNum << " is a perfect square." << std::endl;
    } else {
        std::cout << testNum << " is not a perfect square." << std::endl;
    }

    return 0;
}