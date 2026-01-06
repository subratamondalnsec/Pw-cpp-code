#include <bits/stdc++.h>
using namespace std;
void printOddNumbers(int a, int b) {
    int c=min(a,b);
    int d= max(a,b);
    for(int i = c; i <= d; ++i) {
        if(i % 2 != 0) {
        cout << i << " ";
        }
    }
    cout << endl;
}
int main() {
 
 int a, b;
 cin >> a >> b;
 
 printOddNumbers(a, b);
 
 return 0;
}