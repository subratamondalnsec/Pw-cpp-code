#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++) m[nums[i]]++;
        priority_queue<pi,vector<pi>,greater<pi> >pq;
        for(auto x : m) pq.push({x.second,x.first});
        vector<int> ans;
        priority_queue<int>mx;
        int freq=(pq.top()).first;
       while(pq.size()>0){
            int val=(pq.top()).second;
            if(freq==(pq.top()).first){
                mx.push(val);
                pq.pop();
            }
            else if(freq!=(pq.top()).first){
                while(mx.size()>0){
                    for(int i=1;i<=freq;i++) ans.push_back(mx.top());
                    mx.pop();
               }
               if(mx.size()==0) freq=(pq.top()).first;
            } 
        }
        while(mx.size()>0){
            for(int i=1;i<=freq;i++) ans.push_back(mx.top());
            mx.pop();
       }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1,1,-6,4,5,-6,1,4,1};  // Example input
    
    vector<int> sorted = solution.frequencySort(nums);
    
    // Output the result
    cout << "Sorted by frequency: ";
    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}