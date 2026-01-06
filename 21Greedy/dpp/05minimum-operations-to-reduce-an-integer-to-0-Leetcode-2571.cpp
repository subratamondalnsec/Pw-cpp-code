#include <iostream>
#include <cmath>
using namespace std;

class Solution {//t.c=O(log n) s.c=O(log n) //recusive method
public:
    int minOperations(int n) {
        if(n==0 || n==1) return n;
        int val=1;
        while(val*2<n) val*=2;
        return 1+min(minOperations(n-val),minOperations(val*2-n));
    }
};

class Solution {//t.c=O(log n) s.c=O(1) //greedy method
public:
    int minOperations(int n) {
        if(n==0 || n==1) return n;
        int count = 0;
        while (n>0) {
            int x =1;
            while(x*2<n) x*=2;
            int n1 = x;
            int n2 = x*2;
            int diff1 = abs(n - n1);
            int diff2 = abs(n2 - n);
            if (diff1 < diff2) n = diff1;
            else if (diff1 > diff2) n = diff2;
            else if (diff1 == 0 && n == diff2) n = diff1;
            else n = diff1;
            count++;
        }
        return count;
    }
};

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    Solution solution;
    int result = solution.minOperations(n);

    cout << "The minimum number of operations to make n zero is: " << result << endl;

    return 0;
}
