#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) s.insert(nums[i]);
        }
        return s.size();
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution solution;
    int result = solution.minimumOperations(nums);

    cout << "The minimum number of operations to make all elements zero is: " << result << endl;

    return 0;
}
