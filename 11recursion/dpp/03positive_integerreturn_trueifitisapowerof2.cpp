#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n){
    if (n == 1) return true;
    if (n % 2 == 0) return isPowerOfTwo(n / 2);
    return false;
}
int main(){
    int n;
    cin >> n;
    if (isPowerOfTwo(n)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}