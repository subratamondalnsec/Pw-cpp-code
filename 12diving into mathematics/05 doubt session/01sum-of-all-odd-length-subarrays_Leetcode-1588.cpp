#include <bits/stdc++.h>
using namespace std;
class Solution {//t.c=>O(n^2);s.c=>O(1);
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        //[1,4,2,5,3] n=5
        int n=arr.size();
        int sum=0;
        for(int i=1;i<n;i++) arr[i]+=arr[i-1];
        sum+=arr[n-1];
        int k=3;
        while(k<=n){
            int i=0;
            int j=k-1;
            while(j<n){
                if(i==0)  sum+=arr[j];
                else  sum+=(arr[j]-arr[i-1]);
                j++;
                i++;         
            }
            k+=2;
        }
        return sum;
    }
};

class Solution {//t.c=>O(n);s.c=>O(1);
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        //[1,4,2,5,3] n=5
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++)  sum+= ((n-i)*(i+1) +1)/2 * arr[i] ;
        return sum;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr = {1, 4, 2, 5, 3};
    int result = sol.sumOddLengthSubarrays(arr);
    
    cout << "Sum of all odd-length subarrays: " << result << endl;
    
    return 0;
}