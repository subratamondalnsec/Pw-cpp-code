// Input: arr1[] = {11, 1, 13, 21, 3, 7}, arr2[] = {11, 3, 7, 1} 
// Output: Yes

// Input: arr1[] = {1, 2, 3, 4, 5, 6}, arr2[] = {1, 2, 4} 
// Output: Yes

// Input: arr1[] = {10, 5, 2, 23, 19}, arr2[] = {19, 5, 3} 
// Output: No

#include<bits/stdc++.h>
using namespace std;

// Checks if an array is a subset of another array.
bool isSubset(vector<int> & arr1, vector<int> & arr2, int m, int n) {
  
    // Iterate over each element in the second array
    for (int i = 0; i < n; i++) {
        bool found = false;
      
        // Check if the element exists in the first array
        for (int j = 0; j < m; j++) {
            if (arr2[i] == arr1[j]) {
                found = true;
                break;
            }
        }
      
        // If any element is not found, return false
        if (!found) return false;
    }
  
    // If all elements are found, return true
    return true;
}

int main() {
    vector<int> arr1 = {11, 1, 13, 21, 3, 7};
    vector<int> arr2 = {11, 3, 7, 1};
    int m = arr1.size();
    int n = arr2.size();

    if (isSubset(arr1, arr2, m, n)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
