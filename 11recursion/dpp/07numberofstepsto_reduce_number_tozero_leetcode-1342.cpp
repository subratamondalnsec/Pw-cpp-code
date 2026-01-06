#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int  steps(int nums){
        if(nums==0) return 0;
        if(nums%2==0) return 1+ steps(nums/2);
        else return 1+steps(nums-1);
    }
    int numberOfSteps(int num) {
        int count =0;
        return steps(num);
    }
};

int main() {
    Solution solution;
    
    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    int result = solution.numberOfSteps(num);
    cout << "Number of steps to reduce " << num << " to zero: " << result << endl;
    
    return 0;
}