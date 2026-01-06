#include <bits/stdc++.h>
using namespace std;
int indexOfKey(vector<int>& arr, int currIndex, int n, int key) {
    if (currIndex == n) {
        return -1;
    }
    if (arr[currIndex] == key) {
        return currIndex;
    }
    return indexOfKey(arr, currIndex + 1, n, key);
}
int main() {

    int n, key;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout<<"Target of element : ";
    cin>>key;
    cout<<"Target element in array index : ";
    cout<<indexOfKey(arr,0,n,key);
}
