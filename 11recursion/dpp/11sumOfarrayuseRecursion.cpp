#include <bits/stdc++.h>
using namespace std;
void sumofarray(vector<int>& arr, int currIndex, int n, int sum) {
    if (currIndex == n) {
        cout<<sum;
        return ;
    }
    sum+=arr[currIndex];
    sumofarray(arr, currIndex + 1, n, sum);
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sumofarray(arr,0,n,0);
}