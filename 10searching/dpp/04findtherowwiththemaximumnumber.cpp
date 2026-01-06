#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[4][4] = {{0, 0, 0, 1}, {1, 1, 1, 1}, {1, 0, 0, 1}, {0, 1, 0, 1}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(arr[0]) / sizeof(arr[0][0]);

    int maxcount = INT_MIN;
    int row = -1;

    for(int i = 0; i < n; i++) {
        int lo = 0;
        int hi = m - 1;
        int first_one_index = m; // Default to m to handle no 1s in the row

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(arr[i][mid] == 1) {
                if(mid == 0 || arr[i][mid - 1] == 0) {
                    first_one_index = mid;
                    break;
                }
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        if(maxcount < (m - first_one_index)) {
            maxcount = m - first_one_index;
            row = i;
        }
    }

    cout << "Row with the maximum number of 1's is: " << row << "\nTotal number of 1's: " << maxcount << endl;
}
