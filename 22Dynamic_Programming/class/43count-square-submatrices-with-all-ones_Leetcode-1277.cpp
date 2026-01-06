#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        int ans=0;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j] && i && j) m[i][j]+=min({m[i-1][j],m[i][j-1],m[i-1][j-1]});
                ans+=m[i][j];
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    }; // Example matrix

    int result = sol.countSquares(matrix);
    cout << "Number of square submatrices with all 1s: " << result << endl;

    return 0;
}
