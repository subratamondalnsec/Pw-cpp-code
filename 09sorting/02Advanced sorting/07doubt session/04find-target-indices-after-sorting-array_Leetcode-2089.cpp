#include <bits/stdc++.h>
using namespace std;
// class Solution {//m1
// public:
//     vector<int> targetIndices(vector<int>& arr,int target){
//         sort(arr.begin(),arr.end());
//         int n=arr.size();
//         vector<int>ans;
//         for(int i=0;i<n;i++){
//             if(arr[i]==target) ans.push_back(i);
//             if(arr[i]>target) break;
//         }
//         return ans;       
//     }
// };


class Solution {//m1
public:
    vector<int> targetIndices(vector<int>& arr,int target){
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<int>ans;
        int lo=0;
        int hi=n-1;
        int i=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]==target){
                if(mid==0){
                    i=mid;
                    break;
                }
                else if(arr[mid-1]!=target){
                    i=mid;
                    break;
                }
                else hi=mid-1;
            }
            else if(arr[mid]>target) hi=mid-1;
            else lo=mid+1;
        }
        while(i<n){
            if(arr[i]==target) ans.push_back(i);
            if(arr[i]>target) break;
            i++;
        }
        return ans;       
    }
};

int main() {
    Solution solution;
    
    // Example test cases
    vector<int> arr1 = {1, 2, 5, 2, 3};
    int target1 = 2;
    
    vector<int> arr2 = {1, 2, 5, 2, 3};
    int target2 = 3;
    
    vector<int> arr3 = {1, 2, 5, 2, 3};
    int target3 = 4;
    
    vector<int> result1 = solution.targetIndices(arr1, target1);
    vector<int> result2 = solution.targetIndices(arr2, target2);
    vector<int> result3 = solution.targetIndices(arr3, target3);
    
    // Output results
    cout << "Test Case 1: ";
    for (int idx : result1) {
        cout << idx << " ";
    }
    cout << endl;  // Expected output: 1 2 (since 2 is at indices 1 and 2 after sorting)
    
    cout << "Test Case 2: ";
    for (int idx : result2) {
        cout << idx << " ";
    }
    cout << endl;  // Expected output: 3 (since 3 is at index 3 after sorting)
    
    cout << "Test Case 3: ";
    for (int idx : result3) {
        cout << idx << " ";
    }
    cout << endl;  // Expected output: (empty, since 4 is not in the array)
    
    return 0;
}