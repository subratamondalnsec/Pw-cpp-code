/* Leetcode 1497 */
#include <bits/stdc++.h>
using namespace std;
bool Pairs(int arr[], int n, int k){
    if (n%2!=0) return false;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) freq[((arr[i] % k) + k) % k]++;
    for (int i = 0; i < n; i++) {
        int rem = ((arr[i] % k) + k) % k;
        if (2 * rem == k && freq[rem] % 2 != 0)  return false;
        else if (rem == 0 && freq[rem] %2 != 0)  return false;
        else if (freq[rem] != freq[k - rem]) return false;
    }
    return true;
}
int main(){
    int arr[] = { 2, 5, 6, 8, 5, 3 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    Pairs(arr, n, k) ? cout << "True" : cout << "False";
    return 0;
}
