#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    if (n == 0) return "";
    if (n == 1) return strs[0];
    sort(strs.begin(), strs.end());
    string first = strs[0];
    string last = strs[n - 1];
    string s = "";
    for (int i = 0; i < min(first.size(), last.size()); i++) {
        if (first[i] == last[i]) {
            s += first[i];
        } else {
            return s;
        }
    }
    return s;
}
int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    string result = longestCommonPrefix(strs);
    cout << "The longest common prefix is: " << result << endl;
    
    return 0;
}
