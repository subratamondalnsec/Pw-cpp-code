#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
class Solution {
public:
    typedef pair<int,pair<int,int>> pip;//s.c=O(k);
    vector<int> smallestRange(vector<vector<int>>& nums) {//T.c=O(N∗Logk)  N=total number of element=n*k
        priority_queue<pip ,vector<pip> , greater<pip> >pq;
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][0],{i,0}});
            mx=max(mx,nums[i][0]);
        }
        int mn=pq.top().first;
        int start=mn,end=mx;
        while(true){
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(col==nums[row].size()-1) break;
            pq.push({nums[row][col+1],{row,col+1}});
            mn=pq.top().first;
            mx=max(mx,nums[row][col+1]);
            if(mx-mn<end-start) {
                start=mn;
                end=mx;
            }
        }
        return {start,end};
    }
};

int main() {
    Solution solution;
    
    // Example test case
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };
    
    vector<int> result = solution.smallestRange(nums);
    
    // Output the result
    cout << "Smallest range is: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}