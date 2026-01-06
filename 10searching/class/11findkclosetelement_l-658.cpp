#include <bits/stdc++.h>
using namespace std;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       //s.c.=O(k)
       //t.c=O(logn+klogk)
       int n = arr.size();
        vector<int> ans(k); // k elements ko insert karoonga
        if(x<arr[0]){
        for(int i=0; i<k; i++) {
            ans [i] = arr[i];
        }
        return ans;
    } // 1 2 3 4 5 x = 7 k = 3 005
        if (x>arr[n-1]) {
            int i = n-1;
             int j = k-1;
            while(j>=0){
            ans[j] = arr[i];
         j--;
         i--;
         }
         return ans;
        }
int lo = 0;
int hi = n-1;
int mid=-1;
bool flag = false; // if x is present in arr or not
int t = 0; // representing index of ans
// binary search
while(lo<=hi) {
        mid = lo + (hi-lo)/2;
        if(arr[mid]==x) {
        flag = true; // present
        ans [t] = arr[mid];
     t++;
  break;
}
else if(arr[mid]>x) hi = mid - 1;
else lo= mid + 1;
}
int lb = hi;
int ub = lo;
if(flag==true) {
lb = mid-1;
ub = mid+1;
}
while(t<k && lb>=0 && ub<=n-1) {
int d1 = abs (x - arr[lb]);
int d2 = abs (x -arr[ub]);
if(d1<=d2){
ans [t] = arr[lb];
t++;
lb--;
}
else{ // d1 < d2
ans [t] = arr[ub];
ub++;
t++;
}
} 
if(lb<0){
while(t<k) {
ans [t] = arr[ub];
ub++;
t++;
}
}
if (ub>n-1){
while(t<k) {
ans [t] = arr[lb];
lb--;
t++;
}
}
sort(ans.begin(),ans.end());
return ans;
        };
int main() {
  vector<int> testArray = {1, 2, 3, 4, 5}; // Example sorted array
    int k = 4; // Number of closest elements to find
    int x = 3; // Target value

vector<int> result = findClosestElements(testArray, k, x);
    cout << "The " << k << " closest elements to " << x << " are: ";
    for (int num : result) {
    cout << num << " ";
    }
   cout << endl;

    return 0;
}