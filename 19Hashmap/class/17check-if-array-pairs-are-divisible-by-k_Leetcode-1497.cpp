#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (int ele : arr) {
            ele = ((ele % k) + k) % k; // normalize to non-negative remainder
            mp[ele]++;
        }

        // Check if there are an even number of elements divisible by k (remainder 0)
        if (mp.find(0) != mp.end()) {
            if (mp[0] % 2 != 0) return false;
            mp.erase(0);
        }

        // Check if the frequency of each remainder matches its complement
        for (auto ele : mp) {
            int e = ele.first;
            int rem = k - e;
            if (mp.find(rem) == mp.end()) return false;
            if (mp[rem] != mp[e]) return false;
        }

        return true;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> arr1 = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
    int k1 = 5;
    cout << (solution.canArrange(arr1, k1) ? "True" : "False") << endl;

    // Test case 2
    vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    int k2 = 7;
    cout << (solution.canArrange(arr2, k2) ? "True" : "False") << endl;

    // Test case 3
    vector<int> arr3 = {-10, -2, 1, -1, 3, 8};
    int k3 = 6;
    cout << (solution.canArrange(arr3, k3) ? "True" : "False") << endl;

    return 0;
}
