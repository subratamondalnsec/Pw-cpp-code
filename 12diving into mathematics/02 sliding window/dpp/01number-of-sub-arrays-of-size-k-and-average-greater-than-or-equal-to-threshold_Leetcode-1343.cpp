#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int avg) {
        int n=arr.size();
        int count=0;
        int sum=0;
        for(int i=0 ; i<k ;i++ ){
            sum+=arr[i];
        }
        if((sum/k)>=avg) count++;
        int i=1,j=k;
        while(j<n){
            sum=sum+arr[j]-arr[i-1];
            if((sum/k)>=avg) count++;
            i++;
            j++;
        }
        return count;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> arr = {2, 1, 3, 4, 1};
    int k = 3;
    int avg = 2;

    // Call the function
    int result = solution.numOfSubarrays(arr, k, avg);

    // Output the result
    cout << "Number of subarrays with average >= " << avg << " is: " << result << endl;

    return 0;
}