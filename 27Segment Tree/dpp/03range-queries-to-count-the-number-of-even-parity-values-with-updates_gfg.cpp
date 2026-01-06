#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> seg;
    int n;

    SegmentTree(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        build(nums, 0, 0, n - 1);
    }

    // Helper function to check even parity
    bool isEvenParity(int x) {
        return __builtin_popcount(x) % 2 == 0;
    }

    // Build the segment tree
    void build(vector<int>& nums, int i, int lo, int hi) {
        if (lo == hi) {
            seg[i] = isEvenParity(nums[lo]) ? 1 : 0;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        build(nums, 2 * i + 1, lo, mid);
        build(nums, 2 * i + 2, mid + 1, hi);
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    // Update a value in the segment tree
    void update(int i, int lo, int hi, int& index, int& val, vector<int>& nums) {
        if (lo == hi) {
            nums[index] = val;
            seg[i] = isEvenParity(val) ? 1 : 0;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        if (index <= mid) update(2 * i + 1, lo, mid, index, val, nums);
        else update(2 * i + 2, mid + 1, hi, index, val, nums);
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    // Query the sum in a range
    int query(int i, int lo, int hi, int& l, int& r) {
        if (l > hi || r < lo) return 0;
        if (lo >= l && hi <= r) return seg[i];
        int mid = lo + (hi - lo) / 2;
        int leftSum = query(2 * i + 1, lo, mid, l, r);
        int rightSum = query(2 * i + 2, mid + 1, hi, l, r);
        return leftSum + rightSum;
    }
};

int main() {
    vector<int> nums = {18, 15, 8, 9, 14, 5};
    SegmentTree st(nums);

    // Query 1: Count even parity numbers in range [0, 4]
    int l = 0, r = 4;
    cout << "Even Parity Count (0, 4): " << st.query(0, 0, st.n - 1, l, r) << endl;

    // Update: Change nums[3] to 11
    int index = 3, val = 11;
    st.update(0, 0, st.n - 1, index, val, nums);

    // Query 2: Count even parity numbers in range [0, 4] after update
    cout << "Even Parity Count (0, 4) after update: " << st.query(0, 0, st.n - 1, l, r) << endl;

    return 0;
}
