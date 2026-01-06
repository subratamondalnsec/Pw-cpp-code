/* Problem Link - 
 By subrata mondal */

#include <iostream>//not submit
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
    int minimumEffortforpath(vector<vector<int>>&heights){
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<pp,vector<pp>,greater<pp> >pq;
        result[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int diff=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for(auto d : dir){
                int nx=x+d[0];
                int ny=y+d[1];
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
    }
};