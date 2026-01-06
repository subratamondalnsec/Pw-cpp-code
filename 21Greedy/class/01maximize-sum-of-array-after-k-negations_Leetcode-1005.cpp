#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size() && k != 0) {
            if (nums[i] == 0) break;
            else if (nums[i] < 0) {
                k--;
                nums[i] *= (-1);
                if (i + 1 < nums.size() && (nums[i + 1] < 0 || nums[i + 1] == 0 || nums[i] > nums[i + 1])) 
                    i++;
            }
            else if (nums[i] > 0) {
                if (k % 2 == 0) break;
                else {
                    nums[i] *= (-1);
                    k--;
                }
            }
        }
        int sum = 0;
        for (int i : nums) sum += i;
        return sum;
    }
};

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int> > pq(nums.begin(),nums.end());
        int sum=0;
        for(int i : nums) sum+=i;
        while(k--){
            int ele=pq.top();
            if(ele==0) break;
            pq.pop();
            sum-=ele;
            pq.push(-ele);
            sum+=(-ele);
        }
        return sum;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-2, 9, 3, -5, -1};
    int k = 3;
    int result = solution.largestSumAfterKNegations(nums, k);
    cout << "Largest sum after " << k << " negations: " << result << endl;
    return 0;
}
