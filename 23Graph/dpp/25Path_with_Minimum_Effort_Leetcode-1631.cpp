/* Problem Link - https://leetcode.com/problems/path-with-minimum-effort/description/
 By subrata mondal */

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
#define pp pair<int,pair<int,int> >
public:
    vector<vector<int> >dir={{1,0},{-1,0},{0,1},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>result(m,(vector<int>(n,INT_MAX)));
        priority_queue<pp,vector<pp>,greater<pp> >pq;
        result[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int diff = pq.top().first;
            auto coord=pq.top().second;
            pq.pop();
            int x=coord.first;
            int y=coord.second;
            if(x==m-1 && y==n-1) return diff;
            for(auto d : dir ){
                int nx=x+d[0];
                int ny = y+d[1];
                if(nx>=0 && ny>=0 && nx<m && ny<n){
                    int absdiff=abs(heights[nx][ny]-heights[x][y]);
                    int maxdiff=max(diff,absdiff);
                    if(result[nx][ny]>maxdiff){
                        result[nx][ny]=maxdiff;
                        pq.push({maxdiff,{nx,ny}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};


int main() {
    Solution sol;
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };
    int result = sol.minimumEffortPath(heights);
    cout << "Minimum Effort: " << result << endl;
    return 0;
}
