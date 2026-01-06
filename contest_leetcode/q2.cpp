class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size();

        // Step 1: Calculate the direct adjustment cost
        long long dirctcost = 0;
        for (int i = 0; i < n; ++i) {
            dirctcost += abs(arr[i] - brr[i]);
        }

        // Step 2: Calculate the rearrangement cost
        vector<int> sArr = arr;
        vector<int> sBrr = brr;

        sort(sArr.begin(), sArr.end());
        sort(sBrr.begin(), sBrr.end());

        long long rcost = 0;
        for (int i = 0; i < n; ++i) {
            rcost += abs(sArr[i] - sBrr[i]);
        }
        long long tcost = rcost + k;

        // Step 3: Return the minimum of both strategies
        return min(dirctcost, tcost);
    }
};