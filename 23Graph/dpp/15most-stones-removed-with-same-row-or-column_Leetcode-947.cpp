/* Problem Link - https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
 By subrata mondal */

#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int find(vector<int>&parent,int x){
        // T.c=O(log*(n));
        //this method return which group/cluster x belongs to 
        return parent[x] = (parent[x]==x) ? x : find(parent,parent[x]);
    }
    
    void Union(vector<int>& parent,vector<int>&rank ,int a,int b){
        // T.c=O(log*(n));
        a=find(parent,a);
        b=find(parent,b);
        if(a==b) return ;
        if(rank[a]>=rank[b]){
            rank[a]++;
            parent[b]=a;
        }
        else{
            rank[b]++;
            parent[a]=b;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int mxrow=0,mxcol=0;
        for(auto el : stones){
            mxrow=max(mxrow,el[0]);
            mxcol=max(mxcol,el[1]);
        }
        vector<int> parent(mxrow+mxcol+2);
        vector<int>rank(mxrow+mxcol+2,0);
        for(int i=0;i<mxrow+mxcol+2;i++){
            parent[i]=i;
        }
        unordered_map<int,int>mp;
        for( auto el : stones){
            int nr=el[0];
            int nc=mxrow+el[1]+1;
            Union(parent,rank,nr,nc);
            mp[nr]=1;
            mp[nc]=1;
        }
        int cc=0;
        for(auto it : mp){
            if(find(parent,it.first)==it.first) cc++;
        }
        return stones.size()-cc;
    }
};

int main() {
    // Example input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
    vector<vector<int>> stones = {
        {0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}
    };

    Solution solution;
    int result = solution.removeStones(stones);

    // Output the result
    cout << "Maximum stones that can be removed: " << result << endl;

    return 0;
}