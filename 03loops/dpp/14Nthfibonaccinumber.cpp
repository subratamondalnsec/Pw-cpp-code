#include <bits/stdc++.h>
using namespace std;
    int main( ) {
    int n;
    cin >> n;
    int f0 = 1, f1 = 1;
    if(n==1)  cout << f0 << " ";
    if(n>1)  cout << f0 << " " << f1 << " ";
    for (int i = 3; i <= n; i++) {
        int next = f0 + f1;
        cout << next << " ";
        f0 = f1;
        f1 = next;
    }
}
