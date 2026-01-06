//https://leetcode.com/problems/house-robber/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int Robbery(vector<int>& arr,int i){//recursion
        if(i==arr.size()-1) return arr[i];//single house
        if(i==arr.size()-2) return max(arr[i],arr[i+1]);//double house
        return max(arr[i]+Robbery(arr,i+2),0+Robbery(arr,i+1));
    }
    int rob(vector<int>& nums) {
        return Robbery(nums,0);
    }
};
class Solution {
public:
    int Robbery_memo(vector<int>& arr,int i,vector<int>&dp){//memorization
        if(i==arr.size()-1) return arr[i];//single house
        if(i==arr.size()-2) return max(arr[i],arr[i+1]);//double house
        if(dp[i]!=-1) return dp[i];
        return dp[i]= max(arr[i]+Robbery_memo(arr,i+2,dp) ,0+Robbery_memo(arr,i+1,dp));
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return Robbery_memo(nums,0,dp);
    }
};

class Solution {
public:
    int rob(vector<int>& arr) {//Tabulation 
        int n= arr.size();
        if(n==1) return arr[0];//single house
        if(n==2) return max(arr[0],arr[1]);//double house
        vector<int>dp(n,-1);
        dp[n-1]=arr[n-1];
        dp[n-2]=max(arr[n-2],arr[n-1]);
        for(int i=n-3;i>=0;i--){
            dp[i]=max(arr[i]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }
};

class Solution {//Tabulation
public:
    int rob(vector<int>& arr) {
        int n= arr.size();
        if(n==1) return arr[0];//single house
        if(n==2) return max(arr[0],arr[1]);//double house
        vector<int>dp(arr.size()+1,-1);
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
        }
        return max(dp[n-1],dp[n-2]);
    }
};

class Solution {//space optimisation
public:
    int rob(vector<int>& arr) {
        int n= arr.size();
        if(n==1) return arr[0];//single house
        if(n==2) return max(arr[0],arr[1]);//double house
        int dp[3];
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n;i++){
            dp[2]=max(arr[i]+dp[0],dp[1]);
            dp[0]=dp[1];
            dp[1]=dp[2];
        }
        return dp[2];
    }
};

class Solution {
public:
    vector<int>dp;
    int f(vector<int>&arr,int i){
        if(i>=arr.size())  return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]= max((arr[i]+f(arr,i+2)),f(arr,i+1));  
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return f(nums,0);
    }
};

int main(){
    Solution sol;
    vector<int> arr={2,7,9,3,1};
    int result=sol.rob(arr);
    cout<<" The maximum amount of money you can rob tonight is :"<<result<<endl;

}