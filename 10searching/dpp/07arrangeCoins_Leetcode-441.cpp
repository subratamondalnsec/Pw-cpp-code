#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long long lo=1;
        long long hi=n;
        while(lo<=hi){
            long long k=lo+(hi-lo)/2;
            long long m=k*(k+1)/2;
            if(m==n) return (int) k;
            if(m>n) hi=k-1;
            else lo=k+1;
        }
        return (int)hi;
    }
};

class Solution {
public:
    int arrangeCoins(int n) {
        long long d=(long long)(8*(long long)(n));
        int k=(sqrt(d+1)-1)/2;
        return k;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of coins: ";
    cin >> n;
    int result = solution.arrangeCoins(n);
    cout << "The number of complete rows that can be formed is: " << result << endl;
    return 0;
}
