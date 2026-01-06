#include <iostream>
    int mySqrt(long long x) {
        int lo = 0;
        int hi = x;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if ((mid * mid) == x) return mid;
            else if ((mid * mid) > x) hi = mid - 1;
            else lo = mid + 1;
        }
        return hi;
};

int main() {
 
    long long testValue = 25; // You can change this value to test other cases
    int result =mySqrt(testValue);
    std::cout << "The square root of " << testValue << " is " << result << std::endl;
    return 0;
}
