#include <bits/stdc++.h>
using namespace std;
class Solution {//m1
public:
    int maximumCount(vector<int>& arr){
        int pos=0,neg=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>0) pos++;
            if(arr[i]<0) neg++;
        }
        return max(pos,neg);
    }
};

class Solution {
public:
    int maximumCount(vector<int>& arr){
        int pos=0,neg=0;
        int n=arr.size();
        int lo=0;
        int hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]<=0) lo=mid+1;
            else{
                if(mid>0 && arr[mid-1]>0) hi=mid-1;
                else{
                    pos=n-mid;
                    break;
                }
            }
        }
        lo=0;
        hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]>=0) hi=mid-1;
            else{
                if(mid+1<n && arr[mid+1]<0) lo=mid+1;
                else{
                    neg=mid+1;
                    break;
                }
            }
        }
        return max(pos,neg);
    }
};

int main() {
    Solution solution;
    
    // Example test cases
    vector<int> arr1 = {-1, -2, -3, 3, 4, 5};  // 3 positive, 3 negative
    vector<int> arr2 = {1, 2, 3, 4};  // 4 positive, 0 negative
    vector<int> arr3 = {-1, -2, -3, -4};  // 0 positive, 4 negative
    vector<int> arr4 = {0, 0, 0};  // 0 positive, 0 negative
    
    cout << "Test Case 1: " << solution.maximumCount(arr1) << endl;  // Expected output: 3
    cout << "Test Case 2: " << solution.maximumCount(arr2) << endl;  // Expected output: 4
    cout << "Test Case 3: " << solution.maximumCount(arr3) << endl;  // Expected output: 4
    cout << "Test Case 4: " << solution.maximumCount(arr4) << endl;  // Expected output: 0
    
    return 0;
}