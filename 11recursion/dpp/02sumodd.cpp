#include <bits/stdc++.h>
using namespace std;
int findSum(int curr, int lastNumber) {
 if(curr > lastNumber) return 0;
 if(curr % 2 != 0) return curr + findSum(curr+2, lastNumber);
 return findSum(curr+1, lastNumber);
}
int main() {
 int a, b;
 cin >> a >> b;
 cout << findSum(a, b) << endl;
 return 0;
} 