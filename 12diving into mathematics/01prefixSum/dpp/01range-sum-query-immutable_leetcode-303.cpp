#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int>arr;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        arr=vector<int>(n);
        arr[0]=nums[0];
        for(int i=1;i<n;i++){
            arr[i]=arr[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return arr[right];
        return arr[right]-arr[left-1];
    }
};

int main() {
    // Example input
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    
    // Creating the NumArray object
    NumArray numArray(nums);
    
    // Example queries
    cout << "Sum of range (0, 2): " << numArray.sumRange(0, 2) << endl;  // Output: 1
    cout << "Sum of range (2, 5): " << numArray.sumRange(2, 5) << endl;  // Output: -1
    cout << "Sum of range (0, 5): " << numArray.sumRange(0, 5) << endl;  // Output: -3
    
    return 0;
}