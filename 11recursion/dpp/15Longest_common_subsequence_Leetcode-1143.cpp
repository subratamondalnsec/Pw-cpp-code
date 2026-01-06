#include <bits/stdc++.h>
using namespace std;
int longestCommonSubstring(string& a, string& b, int idxA, int idxB) {
    if (idxA == a.size() || idxB == b.size()) {
        return 0;
    }
    if (a[idxA] == b[idxB]) {
        return 1 + longestCommonSubstring(a, b, idxA + 1, idxB + 1);
    }
    return max(longestCommonSubstring(a, b, idxA + 1, idxB),longestCommonSubstring(a, b, idxA, idxB + 1));
}
int main() {
    string a, b;
    cin >> a >> b;
    int ans = longestCommonSubstring(a, b, 0, 0);
    cout << ans << endl;
    return 0;
}