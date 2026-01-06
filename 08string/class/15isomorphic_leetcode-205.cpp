#include <bits/stdc++.h>
using namespace std;
bool isIsomorphic (string s, string t) {
    if(s.length()!=t.length()) return false;
    vector<int> v(150,1000);
    for(int i=0;i<s.length();i++){
        int idx = (int)s[i];
        if(v[idx]==1000) v[idx] = s[i] - t[i];
        else if (v[idx]!=(s[i]-t[i])) return false;
    }
    // emptying the vector
    for(int i=0;i<150;i++) v[i] = 1000;
    for(int i=0;i<s.length();i++){
        int idx = (int)t[i];
        if(v[idx]==1000) v[idx] = t[i]-s[i];
        else if (v[idx]!=(t[i]-s[i])) return false;
    }
    return true;
}
int main() {
    string s1 = "egg";
    string t1 = "add";
    string s2 = "foo";
    string t2 = "bar";
    string s3 = "paper";
    string t3 = "title";
    cout << "Is '" << s1 << "' isomorphic to '" << t1 << "'? " << (isIsomorphic(s1, t1) ? "Yes" : "No") << endl;
    cout << "Is '" << s2 << "' isomorphic to '" << t2 << "'? " << (isIsomorphic(s2, t2) ? "Yes" : "No") << endl;
    cout << "Is '" << s3 << "' isomorphic to '" << t3 << "'? " << (isIsomorphic(s3, t3) ? "Yes" : "No") << endl;
    return 0;
}