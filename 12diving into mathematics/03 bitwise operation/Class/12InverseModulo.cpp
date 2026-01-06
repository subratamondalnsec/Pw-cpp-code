#include <bits/stdc++.h>
using namespace std;

int gcd_Euclid(int a, int b) {
    if (b == 0) return a;
    return gcd_Euclid(b, a % b);
}

int x, y;
void extendedEuclidAlgo(int a, int b) { 
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    extendedEuclidAlgo(b, a % b);
    int newX = y;
    int newY = x - (a / b) * y;
    x = newX;
    y = newY;
}

int getModuloInverse(int a, int m) {
    if (gcd_Euclid(a, m) == 1) {
        extendedEuclidAlgo(a, m);
        return (x % m + m) % m;  // Ensure the result is positive
    } else {
        return -1;  // No modular inverse if gcd(a, m) != 1
    }
}

int main() {
    int a, m = 1000000007;
    cin >> a;
    cout << "Modular multiplicative inverse is : ";
    cout << getModuloInverse(a, m);
    return 0;
}
