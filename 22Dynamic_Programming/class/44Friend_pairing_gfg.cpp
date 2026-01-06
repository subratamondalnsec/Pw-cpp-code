#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution{
public:
    int countFriendsPairings(int n) { 
        int mod=1e9+7;
        vector<long long >dp(n+1,1);
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=(dp[i-1] +(i-1)*dp[i-2]) % mod;
        }
        return (int) dp[n];
        
    }
};    

int main() {
    Solution sol;
    int n = 5; // Example number of friends

    int result = sol.countFriendsPairings(n);
    cout << "Number of ways " << n << " friends can pair up or stay single: " << result << endl;

    return 0;
}
