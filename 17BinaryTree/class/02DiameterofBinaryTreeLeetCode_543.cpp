#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*class Solution {//method 1
public:
    int maxDia = 0;
    int levels (TreeNode* root) {
        if (root==NULL) return 0;
        return 1 + max(levels (root->left), levels (root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int dia =levels (root->left) + levels(root->right);
        maxDia = max (maxDia,dia);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxDia;
    }
};*/

class Solution {//T.c=O(n^2)->top to bottom
public:
    int maxDia = 0;
    int helper (TreeNode* root) {
        if(root==NULL) return 0;
        int dia = levels (root->left) + levels (root->right);
        maxDia = max(maxDia, dia);
        helper(root->left);
        helper(root->right);
        return maxDia;
    }
    int levels (TreeNode* root) {
        if (root==NULL) return 0;
        return 1 + max(levels (root->left), levels (root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDia = 0; // reinitialise
        return helper(root);
    }
};

int main() {
    // Creating a sample binary tree
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int diameter = solution.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree is: " << diameter << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}