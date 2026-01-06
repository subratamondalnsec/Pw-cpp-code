#include <bits/stdc++.h>
using namespace std;
int square(int n) {
 return n * n;
}
int countNumberOfDigits(int num) {
 int ans = 0;
 while(num > 0) {
 ans++;
 num /= 10;
 }
 return ans;
}
int main() {
 
 int num;
 cin >> num;
 
 int numberOfDigits = countNumberOfDigits(num);
 
 cout << square(numberOfDigits) << endl;
 
 return 0;
}