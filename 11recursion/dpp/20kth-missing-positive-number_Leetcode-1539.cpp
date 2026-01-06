#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n= arr.size();
        int lo=0;
        int hi =n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int missing =arr[mid]-mid-1;
            if(missing <k ) lo =mid+1;
            else hi =mid -1;
        }
        return lo+k;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    // Call the function
    int result = sol.findKthPositive(arr, k);

    // Output the result
    cout << "The " << k << "-th missing positive number is: " << result << endl;

    return 0;
}