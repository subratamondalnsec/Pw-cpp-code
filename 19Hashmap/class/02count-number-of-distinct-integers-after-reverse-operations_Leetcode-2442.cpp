#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
            int a = nums[i];
            int rev = 0;
            while (a > 0) {
                rev = rev * 10 + (a % 10);
                a /= 10;
            }
            s.insert(rev);
        }
        return s.size();
    }
};

int main() {
    Solution solution;
    
    // Sample input
    vector<int> nums = {1, 13, 10, 31, 23};

    // Function call
    int result = solution.countDistinctIntegers(nums);
    
    // Output the result
    cout << "The number of distinct integers is: " << result << endl;

    return 0;
}
