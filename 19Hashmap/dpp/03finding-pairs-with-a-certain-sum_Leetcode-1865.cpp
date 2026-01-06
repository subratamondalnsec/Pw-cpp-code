#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
public:
    unordered_map<int, int> m;
    vector<int> a, b;
    
    // Constructor: Initializes nums1 and nums2
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums2.size(); i++) m[nums2[i]]++;
        a = nums1;
        b = nums2;
    }
    
    // Adds val to nums2[index]
    void add(int index, int val) {
        m[b[index]]--;         // Decrement count of current value in the map
        b[index] += val;       // Update nums2[index] with new value
        m[b[index]]++;         // Increment count of the new value in the map
    }
    
    // Counts the number of pairs (a[i], b[j]) such that a[i] + b[j] == tot
    int count(int tot) {
        int c = 0;
        for (int i = 0; i < a.size(); i++) {
            int x = tot - a[i]; // Find complement in nums2
            if (m.find(x) != m.end()) c += m[x]; // Add the count of complement x
        }
        return c;
    }
};

int main() {
    // Example input
    vector<int> nums1 = {1, 1, 2, 2};  // a
    vector<int> nums2 = {3, 4, 5, 6};  // b
    
    // Instantiate FindSumPairs class
    FindSumPairs* findSumPairs = new FindSumPairs(nums1, nums2);
    
    // Test the count function (find pairs with sum equal to 7)
    cout << "Initial count for total 7: " << findSumPairs->count(7) << endl; // Expected output: 4 (1+6, 1+6, 2+5, 2+5)

    // Test the add function (add 3 to index 2 of nums2)
    findSumPairs->add(2, 3); // nums2 becomes [3, 4, 8, 6]
    
    // Test the count function again (find pairs with sum equal to 8)
    cout << "Count for total 8 after adding 3 to index 2 of nums2: " << findSumPairs->count(8) << endl; // Expected output: 2 (1+7, 1+7)
    
    // Test add function again
    findSumPairs->add(2, -2); // nums2 becomes [3, 4, 6, 6]
    
    // Test the count function for total 8 again
    cout << "Count for total 8 after subtracting 2 from index 2 of nums2: " << findSumPairs->count(8) << endl; // Expected output: 4
    
    return 0;
}
