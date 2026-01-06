#include <bits/stdc++.h>
using namespace std;
// Fomula is dp[N] = dp[N-1] + dp[N-2] + dp[N-3] + dp[N-4] + dp[N-5] + dp[N-6]
int findWaysSumofDice(int N){//pure recursion
    if(N<0) return 0;
    if(N==0) return 1;
    int count=0;
    for(int i=1;i<=6;i++){
        if(N-i>=0)count+=findWaysSumofDice(N-i);
    }
    return count;
}
int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result=findWaysSumofDice(n);
    cout << "The total number of ways is : " <<result <<" to get the sum "<< n<<" by repeatedly throwing a dice."<< endl;
}

int findWaysSumofDice(int N,vector<int>& dp){//recursion + memorization
    if(N<0) return 0;
    if(N==0) return 1;
    if(dp[N]!=-1) return dp[N];
    int count=0;
    for(int i=1;i<=6;i++){
        if(N-i>=0)count+=findWaysSumofDice(N-i,dp);
    }
    return dp[N]= count;
}
int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    vector<int>dp(n+1,-1);
    int result=findWaysSumofDice(n,dp);
    cout << "The total number of ways is : " <<result <<" to get the sum "<< n<<" by repeatedly throwing a dice."<< endl;
}
