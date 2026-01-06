#include<bits/stdc++.h>
#define ll 	long long int
using namespace std;
ll dp[20][(1<<20) + 5];
int grid[4][4] = {
	{0, 20, 42, 25},
	{20, 0, 30, 34},
	{42, 30, 0, 10},
	{25, 34, 10, 0}
};
ll tsp(int mask, int curr, int n) {//n^2*2^n
	if(mask == ((1 << n)-1)) {
		return grid[curr][0];
	}
	if(dp[curr][mask] != -1) return dp[curr][mask];
	ll ans = INT_MAX;
	for(int city = 0; city < n; city++) {
		if((mask & (1<<city)) == 0) {
			ans = min(ans, grid[curr][city] + tsp(mask | (1<<city), city, n));
		}
	}

	return dp[curr][mask] = ans;
}

int main(int argc, char const *argv[]) {
    // Write your code here....
    memset(dp, -1, sizeof(dp));
    cout<<tsp(1, 0, 4)<<"\n";
    return 0;
}
