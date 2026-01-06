/* Problem Link - https://www.geeksforgeeks.org/problems/knight-walk4521/1
 By subrata mondal */

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <stack>
using namespace std;


class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    vector<vector<int>>w={{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
	    if(KnightPos[0]==TargetPos[0] && KnightPos[1]==TargetPos[1] ) return 0;
	    queue<pair<int,pair<int,int> > >q;
	    q.push({0,{KnightPos[0],KnightPos[1]}});
	    // Visited array to avoid revisiting cells
        vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
        visited[KnightPos[0]][KnightPos[1]] = true;
	    while(!q.empty()){
	        int level=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            if(x==TargetPos[0] && y==TargetPos[1] ) return level;
            for(auto d : w){
                int nx=x+d[0];
                int ny=y+d[1];
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && visited[nx][ny]==false){
                    if(nx==TargetPos[0] && ny==TargetPos[1] ) return level+1;
                    q.push({level+1,{nx,ny}});
                    visited[nx][ny]=true;
                }
            }
	    }
	    return -1;
	}
};

int main() {
    Solution sol;

    // Input board size and positions
    int N = 8; // Chessboard size (8x8)
    vector<int> KnightPos = {1, 1}; // Knight's starting position
    vector<int> TargetPos = {8, 8}; // Target position

    // Find the minimum steps to reach the target
    int steps = sol.minStepToReachTarget(KnightPos, TargetPos, N);

    // Output the result
    cout << "Minimum steps to reach target: " << steps << endl;

    return 0;
}