#include <iostream>
#include <vector>
using namespace std;

bool canSortArray(int n, int m, vector<int>& a, vector<int>& b) {
    int bVal = b[0];
    int prev = -1e9; 

    for (int i = 0; i < n; i++) {
        int op1 = a[i];
        int op2 = bVal - a[i];
        if (op1 >= prev && op2 >= prev) {
            prev = min(op1, op2);
        } else if (op1 >= prev) {
            prev = op1;
        } else if (op2 >= prev) {
            prev = op2;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        if (canSortArray(n, m, a, b)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}