#include <bits/stdc++.h>
using namespace std;
int square(int num) {
    return num * num; 
}
void firstNSquares(int n) {
    for(int i = 1; i <= n; ++i) {
    cout << i << " " << square(i) << endl;
 }
}
int main() {
 
    int n;
    cin >> n;
    firstNSquares(n);
    
    return 0;
} 