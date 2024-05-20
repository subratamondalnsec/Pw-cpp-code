#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pascal(int numRows) {
    vector<vector<int>> v;
    for (int i = 0; i < numRows; i++) {
        vector<int> a(i + 1); // i + 1 elements in each row
         v.push_back(a);
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                v[i][j] = 1;
            } else {
                v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
            }
        }
    }
    return v;
}
int main() {
    vector<vector<int>> v = pascal(5);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j <=i; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

