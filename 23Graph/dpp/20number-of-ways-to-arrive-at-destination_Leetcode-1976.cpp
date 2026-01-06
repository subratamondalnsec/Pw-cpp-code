/* Problem Link - 
 By subrata mondal */

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {//using map for dist
#define pp pair<long long int,long long int>
#define ll long long int
public:
    const int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<list<pp> >gr(n);
        for(int i=0;i<roads.size();i++){
            gr[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            gr[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        unordered_map<ll,ll>mp;
        priority_queue<pp,vector<pp>,greater<pp> >pq;
        for (int i = 0; i < gr.size(); i++) {
            mp[i] = LLONG_MAX; // Initialize distances to infinity
        }
        vector<int>way(n,0);
        pq.push({0,0});
        mp[0]=0;
        way[0]=1;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if(curr.first>mp[curr.second]) continue;
            for(auto nei : gr[curr.second]){
                if( mp[nei.first]>mp[curr.second]+nei.second){
                    mp[nei.first]=mp[curr.second]+nei.second;
                    pq.push({mp[curr.second]+nei.second,nei.first});
                    way[nei.first]=way[curr.second];
                }
                else if(mp[nei.first]==mp[curr.second]+nei.second){
                    way[nei.first]= (way[nei.first]+way[curr.second]) %MOD;
                }
            }
        }
        return way[n-1] %MOD;
    }
};


class Solution {//using vector for dist
#define pp pair<long long int,long long int>
#define ll long long int
public:
    const int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<list<pp> >gr(n);
        for(int i=0;i<roads.size();i++){
            gr[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            gr[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pp,vector<pp>,greater<pp> >pq;
        vector<ll> mp(n, LONG_MAX);
        vector<int>way(n,0);
        pq.push({0,0});
        mp[0]=0;
        way[0]=1;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if(curr.first>mp[curr.second]) continue;
            for(auto nei : gr[curr.second]){
                if( mp[nei.first]>mp[curr.second]+nei.second){
                    mp[nei.first]=mp[curr.second]+nei.second;
                    pq.push({mp[curr.second]+nei.second,nei.first});
                    way[nei.first]=way[curr.second];
                }
                else if(mp[nei.first]==mp[curr.second]+nei.second){
                    way[nei.first]= (way[nei.first]+way[curr.second]) %MOD;
                }
            }
        }
        return way[n-1] %MOD;
    }
};

int main() {
    int n = 7; // Number of nodes
    vector<vector<int>> roads = {
        {0, 1, 2}, 
        {0, 2, 4}, 
        {1, 4, 5}, 
        {4, 6, 1}, 
        {3, 2, 1}, 
        {1, 3, 3}, 
        {2, 5, 6}, 
        {5, 6, 1}
    };

    Solution sol;
    cout << sol.countPaths(n, roads) << endl;

    return 0;
}

