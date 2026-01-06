#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


class Solution { //Time Limit Exceeded  69 / 121 testcases passed
public:
    vector<vector<int>>dp;
    int f(int egg,int floor){
        if(egg==0) return 0;
        if(egg==1) return floor;
        if(floor==0 || floor==1) return floor;
        if(dp[egg][floor]!=-1) return dp[egg][floor];
        int mn=INT_MAX;
        for(int k=1;k<=floor;k++){
            int attempt=1+max(f(egg-1,k-1),f(egg,floor-k));
            mn=min(mn,attempt);
        }
        return dp[egg][floor]= mn;
    }
    int superEggDrop(int k, int n) {
        dp.resize(k+10,vector<int>(n+10,-1));
        return f(k,n);
    }
};


class Solution {//Time Limit Exceeded 74 / 121 testcases passed
public:
    vector<vector<int>>dp;
    int f(int egg,int floor){
        if(egg==0) return 0;
        if(egg==1) return floor;
        if(floor==0 || floor==1) return floor;
        if(dp[egg][floor]!=-1) return dp[egg][floor];
        int mn=INT_MAX;
        for(int k=1;k<=floor;k++){
            int attempt=1+max( (dp[egg-1][k-1] !=-1)?dp[egg-1][k-1]:f(egg-1,k-1),(dp[egg][floor-k] !=-1)?dp[egg][ floor-k]:f(egg,floor-k));
            mn=min(mn,attempt);
        }
        return dp[egg][floor]= mn;
    }
    int superEggDrop(int k, int n) {
        dp.resize(k+10,vector<int>(n+10,-1));
        return f(k,n);
    }
};

class Solution {//Time Limit Exceeded 76 / 121 testcases passed
public:
    vector<vector<int>> dp;

    int f(int egg, int floor) {
        if (egg == 0) return 0;
        if (egg == 1) return floor;
        if (floor == 0 || floor == 1) return floor;
        if (dp[egg][floor] != -1) return dp[egg][floor];
        
        int mn = INT_MAX;
        for (int k = 1; k <= floor; k++) {
            int brk = 0, non_brk = 0;
            if (dp[egg - 1][k - 1] != -1) brk = dp[egg - 1][k - 1];
            else {
                brk = f(egg - 1, k - 1);
                dp[egg - 1][k - 1] = brk;
            }
            if (dp[egg][floor - k] != -1) non_brk = dp[egg][floor - k];
            else {
                non_brk = f(egg, floor - k);
                dp[egg][floor - k] = non_brk;
            }
            int attempt = 1 + max(brk, non_brk);
            mn = min(mn, attempt);
        }
        return dp[egg][floor] = mn;
    }

    int superEggDrop(int k, int n) {
        dp.resize(k + 1, vector<int>(n + 1, -1));
        return f(k, n);
    }
};

class Solution {//Time Limit Exceeded  79 / 121 testcases passed
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,0));
        for(int e=1;e<=k;e++){
            for(int f=1;f<=n;f++){
                if(e==1) dp[e][f]=f;
                else if(f==1) dp[e][f]=1;
                else{
                    int mn=INT_MAX;
                    for(int mf=f-1,pf=0;mf>=0,pf<=f-1;mf--,pf++){
                        int v1=dp[e][mf];// egg survives
                        int v2=dp[e-1][pf];//egg breaks
                        int val=max(v1,v2);
                        mn=min(mn,val);
                    }
                    dp[e][f]=1+mn;
                }
            }
        }
        return dp[k][n];
    }
};


/* use  in Binary search */


class Solution { //t.c= O(K∗N∗Log(N)) ,s.c=O(K∗N) memorizatio
public:
    vector<vector<int>>dp;
    int f(int egg,int floor){
        if(egg==0) return 0;
        if(egg==1) return floor;
        if(floor==0 || floor==1) return floor;
        if(dp[egg][floor]!=-1) return dp[egg][floor];
        int mn=1e6,l=1,h=floor,attempt=0;

        while(l<=h){
            int mid=(l+h)/2;
            int left=f(egg-1,mid-1);
            int right=f(egg,floor-mid);
            attempt=1+max(left,right);
            if(left<right) l=mid+1;
            else h=mid-1;
            mn=min(mn,attempt);
        }
        return dp[egg][floor]= mn;
    }
    int superEggDrop(int k, int n) {
        dp.resize(k+10,vector<int>(n+10,-1));
        return f(k,n);
    }
};


class Solution {//Time Complexity: O((n * k) * logn)  Space Complexity: O(n * k) tabulation
public:
    int superEggDrop(int k, int n) {
        if(n==0||n==1) return n;     //Think for base case
        if(k==1) return n;

        vector<vector<int>>dp(k+1,vector<int>(n+1,0));
        for(int e=1;e<=k;e++){
            for(int f=1;f<=n;f++){
                if(e==1) dp[e][f]=f;
                else if(f==1) dp[e][f]=1;
                else{
                    int mn=1e6,l=1,h=f,attempt=0;

                    while(l<=h){
                        int mid=(l+h)/2;
                        int left=dp[e-1][mid-1];
                        int right=dp[e][f-mid];
                        attempt=1+max(left,right);
                        if(left<right) l=mid+1;
                        else h=mid-1;
                        mn=min(mn,attempt);
                    }
                    dp[e][f]=mn;
                }
            }
        }
        return dp[k][n];
    }
};


int main() {
    Solution solution;
    int eggs = 2;
    int floors = 10;
    
    int result = solution.superEggDrop(eggs, floors);
    cout << "Minimum number of attempts needed with " << eggs << " eggs and " << floors << " floors is: " << result << endl;
    
    return 0;
}
