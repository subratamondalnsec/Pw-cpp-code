#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        priority_queue<pair<int,vector<int> > >pq;
        for(int i=0;i<arr.size();i++){
            int x=(arr[i][0]*arr[i][0])+(arr[i][1]*arr[i][1]);
            pq.push({x,arr[i]});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>>ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
int main() {
    Solution solution;
    
    // Sample input: a vector of points and the value of k
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;

    // Get the k closest points to the origin
    vector<vector<int>> result = solution.kClosest(points, k);

    // Print the result
    cout << "The " << k << " closest points to the origin are:\n";
    for (const auto& point : result) {
        cout << "[" << point[0] << ", " << point[1] << "]\n";
    }

    return 0;
}