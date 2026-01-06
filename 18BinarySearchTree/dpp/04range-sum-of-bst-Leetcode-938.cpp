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
    void inorder(TreeNode* root, int low, int high ,int& sum){
        if(root==NULL) return;
        inorder(root->left,low,high,sum);
        if(root->val>=low && root->val<=high) sum+=root->val;
        if(root->val>high) return;
        inorder(root->right,low,high,sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {  
        int sum=0;
        inorder(root,low,high,sum);
        return sum;
    }
};

// Utility function to insert a new node in a binary search tree
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

int main() {
    // Create the binary search tree
    TreeNode* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 18);
    /*  10
       /  \
      5    15
     / \     \
    3   7    18
*/

    // Set range [low, high]
    int low = 7;
    int high = 15;

    // Create an object of Solution class
    Solution sol;

    // Find the sum of values in range [low, high]
    int result = sol.rangeSumBST(root, low, high);

    // Print the result
    cout << "Sum of values between " << low << " and " << high << " is: " << result << endl;

    return 0;
}