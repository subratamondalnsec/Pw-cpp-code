#include <bits/stdc++.h>
using namespace std;
class solution{
public:
   vector<int>runningSum(vector<int>& nums){
        int n=nums.size();
    //    vector<int>run(n);
    //    run[0]=nums[0];
    //    for(int i=1;i<n;i++){
    //     run[i]=run[i-1]+nums[i];
    //    }
    //    return run;
    for(int i=1;i<n;i++){
        nums[i]=nums[i]+nums[i-1];
    }
    return nums;
  }
};  
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    
    solution sol;
    vector<int> result = sol.runningSum(nums);
    
    // Output the result
    cout << "Running sum: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}                                 