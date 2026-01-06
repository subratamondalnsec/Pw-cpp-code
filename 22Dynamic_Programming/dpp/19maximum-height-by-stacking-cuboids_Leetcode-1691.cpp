#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int f(vector<vector<int>>& c, int prev, int i) {
        if (i == c.size()) return 0;
        if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

        int take = 0;
        if (prev == -1 || (c[prev][0] <= c[i][0] && c[prev][1] <= c[i][1] && c[prev][2] <= c[i][2])) {
            take = c[i][2] + f(c, i, i + 1);
        }
        int leave = f(c, prev, i + 1);
        return dp[i][prev + 1] = max(take, leave);
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& i : cuboids) sort(i.begin(), i.end());
        sort(cuboids.begin(), cuboids.end());
        dp.resize(cuboids.size() + 10, vector<int>(cuboids.size() + 10, -1));
        return f(cuboids, -1, 0);
    }
};

class Solution {
public:
    int maxHeight(vector<vector<int>>& c) {
        int n=c.size();
        for(auto &i : c ) sort(i.begin(),i.end());
        sort(c.begin(),c.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int prev=n-1;prev>=-1;prev--){
                int take=0;
                if(prev==-1 || (c[prev][0]<=c[i][0] &&c[prev][1]<=c[i][1] && c[prev][2]<=c[i][2])){
                    take=c[i][2]+dp[i+1][i+1];
                }
                int leave = dp[i+1][prev+1];
                dp[i][prev+1]= max(take,leave);
            }
        }
        return dp[0][0];
    }
};

class Solution {
public:
    int maxHeight(vector<vector<int>>& c) {
        int n=c.size();
        for(auto &i : c ) sort(i.begin(),i.end());
        sort(c.begin(),c.end());
        vector<int>curr(n+1,0),last(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int prev=n-1;prev>=-1;prev--){
                int take=0;
                if(prev==-1 || (c[prev][0]<=c[i][0] &&c[prev][1]<=c[i][1] && c[prev][2]<=c[i][2])){
                    take=c[i][2]+last[i+1];
                }
                int leave = last[prev+1];
                curr[prev+1]= max(take,leave);
            }
            last=curr;
        }
        return last[0];
    }
};


int main() {
    Solution solution;
    vector<vector<int>> cuboids = {
        {4, 6, 7},
        {1, 2, 3},
        {4, 5, 6},
        {10, 12, 32}
    };
    
    int result = solution.maxHeight(cuboids);
    cout << "The maximum height that can be achieved by stacking cuboids is: " << result << endl;

    return 0;
}
