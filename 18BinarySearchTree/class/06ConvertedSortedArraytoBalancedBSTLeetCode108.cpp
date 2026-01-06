#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* helper (vector<int>& arr, int lo, int hi){
        if(lo>hi) return NULL;
        int mid = lo + (hi-lo)/2;
        TreeNode* root = new TreeNode (arr[mid]);
        root->left = helper(arr, lo, mid-1);
        root->right = helper(arr,mid+1,hi);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        int n = arr.size();
        return helper (arr,0,n-1);
    }
};

// Helper function to print the tree inorder (for verification purposes)
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}
int main() {
    Solution solution;

    // Sorted array
    std::vector<int> arr = { -10, -3, 0, 5, 9 };

    // Convert sorted array to BST
    TreeNode* root = solution.sortedArrayToBST(arr);

    // Print the BST inorder (for verification purposes)
    std::cout << "Output of the BST: ";
    printLevelOrder(root);
    std::cout << std::endl;

    return 0;
}

