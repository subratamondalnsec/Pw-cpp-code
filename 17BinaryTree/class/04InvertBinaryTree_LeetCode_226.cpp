#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*class Solution {
public:
    void helper (TreeNode* root){
        if(root==NULL) return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        helper(root->left);
        helper(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};*/

// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if(root==NULL) return NULL;
//         TreeNode* temp = root->left;
//         root->left = root->right;
//         root->right = temp;
//         invertTree(root->left);
//         invertTree(root->right);
//         return root;
//     }
// };

class Solution {
public:
    void helper (TreeNode* root) {
        if (root==NULL) return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        helper(root->left);
        helper(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};

void printInOrder(TreeNode* node) {
    if (node == NULL) return;
    printInOrder(node->left);
    cout << node->val << " ";
    printInOrder(node->right);
}

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

    cout << "Original tree in-order: ";
    printInOrder(root);
    cout << endl;

    Solution solution;
    TreeNode* invertedRoot = solution.invertTree(root);

    cout << "Inverted tree in-order: ";
    printInOrder(invertedRoot);
    cout << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}