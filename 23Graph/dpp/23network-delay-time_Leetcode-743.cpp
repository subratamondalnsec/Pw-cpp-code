/* Problem Link - https://leetcode.com/problems/network-delay-time/
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


class Solution {//using vector in destation
#define pp pair<int,int>
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<list<pp> >gr(n+1);
        for(int i=0;i<times.size();i++){
            gr[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pp,vector<pp>,greater<pp> >pq;
        vector<int>mp(n+1,INT_MAX);
        unordered_set<int>vis;
        pq.push({0,k});
        mp[k]=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            if(vis.count(curr.second)) continue;
            vis.insert(curr.second);
            for(auto nei : gr[curr.second]){
                if(!vis.count(nei.first) && mp[nei.first]>mp[curr.second]+nei.second ){
                    mp[nei.first]=mp[curr.second]+nei.second;
                    pq.push({mp[curr.second]+nei.second,nei.first});
                }
            }
        }
        if(vis.size()!=n) return -1;
        int mx=0;
        for(int i=1;i<=n;i++){
            mx=max(mx,mp[i]);
        }
        return mx;
    }
};



class Solution {//using map in destation
#define pp pair<int,int>
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<list<pp> >gr(n+1);
        for(int i=0;i<times.size();i++){
            gr[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pp,vector<pp>,greater<pp> >pq;
        unordered_map<int,int>mp;
        for(int i=0;i<=n;i++){
            mp[i]=INT_MAX;
        }
        unordered_set<int>vis;
        pq.push({0,k});
        mp[k]=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            if(vis.count(curr.second)) continue;
            vis.insert(curr.second);
            for(auto nei : gr[curr.second]){
                if(!vis.count(nei.first) && mp[nei.first]>mp[curr.second]+nei.second ){
                    mp[nei.first]=mp[curr.second]+nei.second;
                    pq.push({mp[curr.second]+nei.second,nei.first});
                }
            }
        }
        if(vis.size()!=n) return -1;
        int mx=0;
        for(int i=1;i<=n;i++){
            mx=max(mx,mp[i]);
        }
        return mx;
    }
};

int main() {
    Solution solution;
    // Example Input
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4, k = 2;

    // Calling the function and printing the result
    int result = solution.networkDelayTime(times, n, k);
    cout << "Network Delay Time: " << result << endl;

    return 0;
}