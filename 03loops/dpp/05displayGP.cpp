#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
cin >> n;
int a = 3, r = 4;
    // while (n--) {
    //     cout << a << " ";
    //     a *= r;
    // }

    for (int i=1;i<=n;i++) {
        cout << a << " ";
        a *= r;
    }
}
