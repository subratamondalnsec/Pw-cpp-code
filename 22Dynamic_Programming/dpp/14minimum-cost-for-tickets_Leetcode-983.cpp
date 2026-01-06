#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int>dp;
    int f(vector<int>& days, vector<int>& costs,int i){
        if(i>=days.size()) return 0;// base case
        if(dp[i]!=-1) return dp[i];
        int option1=costs[0]+f(days,costs,i+1);//day1 ticket
        //day 7 ticket
        int j;
        for(j=i;j<days.size() && days[j]<days[i]+7;j++);
        int option2=costs[1]+f(days,costs,j);
        //30 day ticket
        for(j=i;j<days.size() && days[j]<days[i]+30;j++);
        int option3=costs[2]+f(days,costs,j);
        return dp[i]= min({option1,option2,option3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size()+10,-1);
        return f(days,costs,0);
    }
};

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,INT_MAX);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int option1=costs[0]+dp[i+1];//day1 ticket
            //day 7 ticket
            int j;
            for(j=i;j<n&& days[j]<days[i]+7;j++);
            int option2=costs[1]+dp[j];
            //30 day ticket
            for(j=i;j<n && days[j]<days[i]+30;j++);
            int option3=costs[2]+dp[j];
            dp[i]= min({option1,option2,option3});
        }
        return dp[0];
    }
};

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n=days.size();
        int ans=0;
        queue<pair<int,int>>month;
        queue<pair<int,int>>week;

        for(int day : days){
            //remove expire date
            while(!month.empty() && month.front().first+30<=day) month.pop();

            while(!week.empty() && week.front().first+7<=day) week.pop();
            // add cost for current day
            week.push(make_pair(day,ans+cost[1]));
            month.push(make_pair(day,ans+cost[2]));

            // update ans

            ans=min({ans+cost[0],month.front().second,week.front().second});
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> days = {1, 4, 6, 7, 8, 20}; // example input
    vector<int> costs = {2, 7, 15};         // example ticket costs
    int result = solution.mincostTickets(days, costs);
    cout << "Minimum cost for tickets: " << result << endl;
    return 0;
}

