#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int n) {
    int k = to_string(n).size();
    int s = 0;
    int x = n;
    while (x > 0) {
        int digit = x % 10;
        int power = 1;
        for (int i = 0; i < k; ++i) {//s =s + (pow(x % 10, k));
            power *= digit;
        }
        s += power;
        x /= 10;
    }
    return s == n;
}

int main() {
    for (int i = 1; i <= 5000; ++i) {
        if (isArmstrong(i)) {
            cout << i << endl;
        }
    }
    return 0;
}
