#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int rev(int n){
        int r=0;
        while(n>0){
            r=r*10+n%10;
            n/=10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            nums[i]-=rev(nums[i]);
            m[nums[i]]++;
        }
        int count=0;
        for(int i=0;i<nums.size();i++){ 
            if(m.find(nums[i])!=m.end()){
                count=count%1000000007;
                count+=(m[nums[i]]-1);
                m[nums[i]]--;
            }
        }
        return count%1000000007;
    }
};
class Solution {
public:
    int rev(int n){
        int r=0;
        while(n>0){
            r=r*10+n%10;
            n/=10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        int count=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            nums[i]-=rev(nums[i]);
            if(m.find(nums[i])!=m.end()){
                count=count%1000000007;
                count+=m[nums[i]];
            }
            m[nums[i]]++;
        }
        return count%1000000007;
    }
};
int main() {
    Solution sol;
    
    // Example input
    vector<int> nums = {42, 11, 1, 97};  // Input array
    
    // Debug log for the input array
    cout << "Input array: ";
    for (int ele : nums) {
        cout << ele << " ";
    }
    cout << endl;
    
    // Call the function and get the result
    int result = sol.countNicePairs(nums);
    
    // Output the result
    cout << "Number of nice pairs: " << result << endl;
    
    return 0;
}