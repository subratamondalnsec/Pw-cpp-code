#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        priority_queue<int>pq;
        for(int i=0; i < arr.size(); i++) pq.push(arr[i]);
        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if((x - y) != 0) pq.push(x - y);
        }
        if(pq.size() == 0) return 0;
        return pq.top();
    }
};
class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        while(arr.size()>1){
            sort(arr.begin(),arr.end());
            int x=arr[arr.size()-1];
            arr.pop_back();
            int y=arr[arr.size()-1];
            arr.pop_back();
            if(x!=y) arr.push_back(x-y);
        }
        if(arr.size()==1) return arr[0];
        else return 0;
        
    }
};
int main() {
    Solution sol;
    vector<int> stones = {2, 7, 4, 1, 8, 1}; // Example input
    int result = sol.lastStoneWeight(stones);
    cout << "Last stone weight: " << result << endl;
    return 0;
}
