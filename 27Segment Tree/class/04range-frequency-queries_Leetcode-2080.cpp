/* problem link : https://leetcode.com/problems/range-frequency-queries/
By subrata mondal */
#include<bits/stdc++.h>
using namespace std;

class RangeFreqQuery {
#define mp unordered_map<int,int>
public:
    vector<mp> seg;
    int n;

    // Helper function to merge two frequency maps
    mp addmap(mp m1, mp m2) {
        mp m = m1;  // Start with m1
        for (auto x : m2) {
            int key = x.first, freq = x.second;
            m[key] += freq;  // Add frequency for existing keys, or insert new ones
        }
        return m;
    }

    // Build the segment tree
    void build_segment_Tree(vector<int>& nums, int i, int lo, int hi) {
        if (lo == hi) {
            int key = nums[hi];
            seg[i][key] = 1;  // Single frequency for the element
            return;
        }
        int mid = lo + (hi - lo) / 2;
        build_segment_Tree(nums, 2 * i + 1, lo, mid);
        build_segment_Tree(nums, 2 * i + 2, mid + 1, hi);
        seg[i] = addmap(seg[2 * i + 1], seg[2 * i + 2]);  // Merge child maps
    }

    // Constructor
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n);  // Resize the segment tree
        build_segment_Tree(arr, 0, 0, n - 1);  // Build the tree
    }

    // Query the frequency of a value in the given range
    int getfreq(int i, int lo, int hi, int& left, int& right, int& value) {
        if (left > hi || right < lo) return 0;  // No overlap
        if (lo >= left && hi <= right) {  // Complete overlap
            if (seg[i].find(value) == seg[i].end()) return 0;
            else return seg[i][value];
        }
        int mid = lo + (hi - lo) / 2;
        int leffreq = getfreq(2 * i + 1, lo, mid, left, right, value);
        int rightfreq = getfreq(2 * i + 2, mid + 1, hi, left, right, value);
        return leffreq + rightfreq;  // Combine frequencies
    }

    int query(int left, int right, int value) {
        return getfreq(0, 0, n - 1, left, right, value);
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 2, 1, 2, 3};
    RangeFreqQuery obj(arr);

    // Query frequency of 2 in range [1, 4]
    cout << obj.query(1, 4, 2) << endl;  // Output: 2

    // Query frequency of 3 in range [2, 6]
    cout << obj.query(2, 6, 3) << endl;  // Output: 2

    // Query frequency of 1 in range [0, 6]
    cout << obj.query(0, 6, 1) << endl;  // Output: 2

    return 0;
}
