#include <iostream>
#include <string>
using namespace std;

int minimizeStringLength(string s) {
    int n = s.length();
    int i = 0;
    while (i < n - 1) {
        if (s[i] == s[i + 1]) {
            // Perform the operation: replace s[i] with any character and remove s[i+1]
            if(n==1) break;
            s.erase(i + 1, 1);
            n--;
            if(n==1) break;
            if(i!=0) s[i]=s[i-1];
            else if(i==0) s[i]=s[i+1];
            // Reset i to 0 to check for new consecutive pairs after modification
            i = 0;
        } else {
            i++;
        }
    }
    return s.length();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << minimizeStringLength(s) << endl;
    }
    return 0;
}