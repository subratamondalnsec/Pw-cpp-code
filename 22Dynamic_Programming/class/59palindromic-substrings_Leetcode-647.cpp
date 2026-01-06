#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector< vector<int> >dp(n,vector<int>(n,0));
        int count=n;
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int k=1;k<n;k++){
            for(int i=0,j=k; i<n-k,j<n ;i++,j++){
                if(s[i]!=s[j]) dp[i][j]=0;
                else {
                    if(j==i+1){// length 2 ar sub string 
                        dp[i][j]=1;
                        count++;
                    } 
                    else if(dp[i+1][j-1]==1){
                        dp[i][j]=1;
                        count++;
                    }
                    else  dp[i][j]=0;
                }
            }
        }
        return count;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector< vector<int> >dp(n,vector<int>(n,1));
        int count=n;
        for(int k=1;k<n;k++){
            for(int i=0,j=k; i<n-k,j<n ;i++,j++){
                if(s[i]!=s[j]) dp[i][j]=0;
                else {
                    if(j==i+1){// length 2 ar sub string 
                        dp[i][j]=1;
                        count++;
                    } 
                    else if(dp[i+1][j-1]==1){
                            dp[i][j]=1;
                            count++;
                    }
                    else  dp[i][j]=0;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    string s = "aaa";
    cout << "The number of palindromic substrings is : " << sol.countSubstrings(s) << endl;
    return 0;
}