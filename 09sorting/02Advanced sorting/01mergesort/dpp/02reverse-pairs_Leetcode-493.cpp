#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     int inversion(vector<int>& v1,vector<int>& v2){
//        int count=0;
//         int i=0;
//         int j=0;
//         while(i<v1.size() && j<v2.size()){
//             if((long long)v1[i]>(long long)2*v2[j]){ 
//                 count+=(v1.size()-i);
//                 j++;
//             }
//             else i++;
//         }
//         return count;
// }
//     void merge(vector<int>& v1,vector<int>& v2,vector<int>& res ){
//      int n=v1.size(),m=v2.size();
//      int i=0, j=0, k=0;
//     while(i<=n-1&&j<=m-1){
//         if(v1[i]<v2[j]) res[k++]=v1[i++];
//         else  res[k++]=v2[j++];
//     }
// if(i==n) while(j<=m-1)  res[k++]=v2[j++];
// if(j==m) while(i<=n-1) res[k++]=v1[i++];
// }
// int mergesort(vector<int>&v){
//     int counter =0;
//     int n=v.size();
//     if(n==1) return 0; 
//     int n1=n/2,n2 =n-n/2;
//     vector<int>a(n1),b(n2);
//     for(int i=0;i<n1;i++)  a[i]=v[i];
//     for(int i=0;i<n2;i++)  b[i]=v[i+n1];
//     counter+= mergesort(a);
//     counter+= mergesort(b);
//     counter+=inversion(a,b);   //count the inversion
//     merge(a,b,v);
//     a.clear();
//     b.clear();
//     return counter;
// }
//     int reversePairs(vector<int>& nums) {
//        return mergesort(nums);
//     }
// };

class Solution {
public:
    void merge(vector<int>& v, int low, int mid, int high,int &ans) {
        int i = low, j = mid + 1;
        // Counting reverse pairs
        while (i <= mid && j <= high) {
            if ((long long)v[i] > (long long)2 * v[j]) {
                ans += mid - i + 1;  // Count reverse pairs
                j++;
            } 
            else  i++;  
        }
        // Merge the two sorted halves
        i = low, j = mid + 1;
        vector<int> a;
        while (i <= mid && j <= high) {
            if (v[i] <= v[j]) a.push_back(v[i++]);
            else   a.push_back(v[j++]);
        }
        // Copy any remaining elements
        while (i <= mid)  a.push_back(v[i++]);
        while (j <= high) a.push_back(v[j++]);
        // Copy sorted elements back into original array
        for (int k = low; k <= high; k++) {
            v[k] = a[k - low];
        }
    }
    void mergesort(vector<int>& v, int low, int high,int &ans) {
        if (low >= high) return;

        int mid = (low + high) / 2;
        mergesort(v, low, mid,ans);
        mergesort(v, mid + 1, high,ans);
        merge(v, low, mid, high,ans);
    }
    int reversePairs(vector<int>& nums) {
        int ans=0;
         mergesort(nums, 0, nums.size() - 1,ans);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 2, 3, 1};
    int result = solution.reversePairs(nums);
    cout << "Number of reverse pairs: " << result << endl;
    return 0;
}