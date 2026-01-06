/* Problem Link - https://leetcode.com/problems/detonate-the-maximum-bombs/
 By subrata mondal */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_set>
#include <list>
using namespace std;

class Solution {//dfs
#define ll long long int
public:

    vector<list<int> >gr;
    void dfs(int node, unordered_set<int>&s){
        s.insert(node);
        for(int nei : gr[node]){
            if(s.find(nei) == s.end()) {
                dfs(nei,s);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        gr.resize(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                ll x1=bombs[i][0];
                ll y1=bombs[i][1];
                ll r1=bombs[i][2];

                ll x2=bombs[j][0];
                ll y2=bombs[j][1];
                ll r2=bombs[j][2];

                ll d=((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
                if((ll)(r1*r1)>=d) gr[i].push_back(j);
            }
        }
        int result=0;
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            dfs(i,s);
            int c=s.size();
            result=max(result,c);
            s.clear();
        }
        return result;
    }
};


class Solution {//bfs
#define ll long long int
public:

    vector<list<int> >gr;
    void bfs(int node, unordered_set<int>&s){
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int curr=q.front();
            s.insert(curr);
            q.pop();
            for(int nei : gr[curr]){
                if(s.find(nei) == s.end()) {
                    q.push(nei);
                }
            }
        }
        
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        gr.resize(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                ll x1=bombs[i][0];
                ll y1=bombs[i][1];
                ll r1=bombs[i][2];

                ll x2=bombs[j][0];
                ll y2=bombs[j][1];
                ll r2=bombs[j][2];

                ll d=((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
                if((ll)(r1*r1)>=d) gr[i].push_back(j);
            }
        }
        int result=0;
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            bfs(i,s);
            int c=s.size();
            result=max(result,c);
            s.clear();
        }
        return result;
    }
};


int main() {
    // Example input: each bomb has [x, y, radius]
    vector<vector<int>> bombs = {
        {2, 1, 3}, // Bomb 0
        {6, 1, 4}, // Bomb 1
        {4, 5, 2}  // Bomb 2
    };

    // Create a Solution object
    Solution solution;

    // Call the function and get the result
    int result = solution.maximumDetonation(bombs);

    // Output the result
    cout << "Maximum bombs that can be detonated: " << result << endl;

    return 0;
}
