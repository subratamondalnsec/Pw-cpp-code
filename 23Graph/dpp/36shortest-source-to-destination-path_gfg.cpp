/* Problem Link - https://www.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1
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
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[0][0]==0) return -1;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        A[0][0]=0;
         vector<vector<int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int level=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            if(X==x && Y==y) return level;
            for(auto d : dir){
                int nx=x+d[0];
                int ny=y+d[1];
                if(nx>=0 && nx<N && ny>=0 && ny<M && A[nx][ny]==1){
                    if(X==nx && Y==ny) return level+1;
                    A[nx][ny]=0;
                    q.push({level+1,{nx,ny}});
                }
            }
        }
        return -1;
    }
};

int main() {
    // Dimensions of the matrix
    int N = 4, M = 4;

    // Binary matrix A
    vector<vector<int>> A = {
        {1, 1, 1, 0},
        {1, 0, 1, 1},
        {0, 1, 1, 0},
        {1, 1, 1, 1}
    };

    // Target coordinates
    int X = 3, Y = 3;

    Solution sol;
    int result = sol.shortestDistance(N, M, A, X, Y);

    cout << "Shortest Distance to (" << X << ", " << Y << "): " << result << endl;

    return 0;
}