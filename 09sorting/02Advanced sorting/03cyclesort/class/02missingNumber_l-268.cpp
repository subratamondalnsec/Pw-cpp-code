#include <bits/stdc++.h>
using namespace std;
class solution{
public:
     int missingNumber(vector<int>& nums){
        int n=nums.size();
        vector<bool>check(n+1,false);
        for(int i=0;i<n;i++){
            int ele=nums[i];
            check[ele]=true;
        }
         for(int i=0;i<=n;i++){
            if(check[i]==false) return i;
         }
         return -1;
     }
};
/* m2*/
/*class solution{
public:
     int missingNumber(vector<int>& nums){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
         return (n*(n+1))/2-sum;
     }
};*/
/*m3*/
// class solution{
// public:
//      int missingNumber(vector<int>& nums){
//         int n=nums.size();
//        int i=0;
//        while(i<n){
//         int correctIdx=nums[i];
//         if(correctIdx==i||nums[i]==n) i++;
//         else swap(nums[i],nums[correctIdx]);
//        }
//         for(int i=0;i<n;i++){
//             if(nums[i]!=i) return i;
//         }
//         return n;
//      }
// };
int main() {
    solution solution;
    int n;
    
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int missing = solution.missingNumber(nums);
    cout << "The missing number is: " << missing << endl;
    
    return 0;
}
