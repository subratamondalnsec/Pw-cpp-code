#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long sum;     // Stores the sum of the range
    long long lazy;    // Lazy propagation value
    Node *left, *right; // Pointers to left and right child

    Node() : sum(0), lazy(0), left(nullptr), right(nullptr) {}
};

class DynamicSegmentTree {
private:
    Node *root;
    int size;

    void propagate(Node *node, int start, int end) {
        if (!node || node->lazy == 0) return;

        // Apply the lazy value to the current node
        node->sum += (end - start + 1) * node->lazy;

        // Propagate lazy value to children
        if (start != end) {
            if (!node->left) node->left = new Node();
            if (!node->right) node->right = new Node();
            node->left->lazy += node->lazy;
            node->right->lazy += node->lazy;
        }

        // Clear the lazy value of the current node
        node->lazy = 0;
    }

    void updateRange(Node *node, int start, int end, int l, int r, long long val) {
        propagate(node, start, end);

        // Out of range
        if (!node || start > r || end < l) return;

        // Complete overlap
        if (start >= l && end <= r) {
            node->lazy += val;
            propagate(node, start, end);
            return;
        }

        // Partial overlap
        int mid = start + (end - start) / 2;
        if (!node->left) node->left = new Node();
        if (!node->right) node->right = new Node();

        updateRange(node->left, start, mid, l, r, val);
        updateRange(node->right, mid + 1, end, l, r, val);

        node->sum = (node->left ? node->left->sum : 0) + (node->right ? node->right->sum : 0);
    }

    long long queryRange(Node *node, int start, int end, int l, int r) {
        propagate(node, start, end);

        // Out of range
        if (!node || start > r || end < l) return 0;

        // Complete overlap
        if (start >= l && end <= r) return node->sum;

        // Partial overlap
        int mid = start + (end - start) / 2;
        long long leftSum = queryRange(node->left, start, mid, l, r);
        long long rightSum = queryRange(node->right, mid + 1, end, l, r);

        return leftSum + rightSum;
    }

public:
    DynamicSegmentTree(int n) : size(n) {
        root = new Node();
    }

    void update(int l, int r, long long val) {
        updateRange(root, 0, size - 1, l, r, val);
    }

    long long query(int l, int r) {
        return queryRange(root, 0, size - 1, l, r);
    }
};

int main() {
    int n = 1e9; // Define the maximum possible range (0 to n-1)

    DynamicSegmentTree segTree(n);

    // Update range [2, 5] by adding 10
    segTree.update(2, 5, 10);

    // Query the sum in range [2, 5]
    cout << "Sum in range [2, 5]: " << segTree.query(2, 5) << endl;

    // Update range [3, 7] by adding 5
    segTree.update(3, 7, 5);

    // Query the sum in range [4, 6]
    cout << "Sum in range [4, 6]: " << segTree.query(4, 6) << endl;

    return 0;
}
