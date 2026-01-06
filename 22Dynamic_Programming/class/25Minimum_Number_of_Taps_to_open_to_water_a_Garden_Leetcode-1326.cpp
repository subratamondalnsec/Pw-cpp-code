/*
Code BY Subrata Mondal
problem link : https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {//greedy method  
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>StartEnd(n+1,0);
        for(int i=0;i<=n;i++){
            int start=max(0,i-ranges[i]);
            int end=min(n,i+ranges[i]);
            StartEnd[start]=max(StartEnd[start],end);
        }
        int taps=0,maxEnd=0,currEnd=0;
        for(int i=0;i<=n;i++){
            if(i>maxEnd) return -1;
            if(i>currEnd){
                currEnd=maxEnd;
                taps++;
            }
            maxEnd=max(maxEnd,StartEnd[i]);
        }
        return taps ;
    }
};

//Approach-2 (Recursion + Memo)
class Solution {  //Time Limit Exceeded 40 / 41 testcases passed
public:
    map<pair<int,int>,int> mp;
    int N;
    int solve(int i, int maxEnd, vector<pair<int,int>>& range) {
        if(i >= range.size())
            return maxEnd >= N ? 0 : 1e9;

        if(range[i].first > maxEnd)
            return 1e9;

        if(mp.find({i,maxEnd}) != mp.end())
            return mp[{i,maxEnd}];

        int not_open_tap = solve(i+1, maxEnd , range);
        
        int open_tap     = 1 + solve(i+1, max(maxEnd, range[i].second), range);

        return mp[{i, maxEnd}] = min(open_tap, not_open_tap); 
    }
    
    int minTaps(int n, vector<int>& ranges) {
        N = n;
        
        vector<pair<int,int>> range;

        for(int i = 0; i < ranges.size(); i++) {
            
            int start = max(0, i - ranges[i]);
            int end   = min(n, i + ranges[i]);
            
            range.push_back({start, end});
            
        }
        
        sort(range.begin(), range.end());
        
        int ans = solve(0, 0, range);
        
        return ans == 1e9 ? -1 : ans;
    }
};

class Solution{
public:
    int minTaps(int n,vector<int>&ranges){
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<=n;i++){
            int start=max(0,i-ranges[i]);
            int end=min(n,i+ranges[i]);
            int ans=INT_MAX;
            for(int j=start;j<=end;j++){
                ans=min(ans,dp[j]);
            }
            if(ans!=INT_MAX) dp[end]=min(dp[end],ans+1);
        }
        return dp[n]==INT_MAX ? -1 : dp[n];
    }
};
int main(){
    vector<int>arr={3,4,1,1,0,0};
    int n=arr.size()-1;
    Solution sol;
    int result=sol.minTaps(n,arr);
    cout<<"Minimum Tap of the garden : "<<result;
}