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
    void trim(TreeNode* root, int lo, int hi){
        if(root==NULL) return;
        while(root->left!=NULL){
            if(root->left->val < lo ) root->left=root->left->right;
            else if(root->left->val > hi) root->left=root->left->left;
            else break;
        }
        while(root->right!=NULL){
            if(root->right->val > hi ) root->right=root->right->left;
            else if(root->right->val < lo) root->right=root->right->right;
            else break;
        }
        trim(root->left,lo,hi);
        trim(root->right,lo,hi);
    }
    TreeNode* trimBST(TreeNode* root, int lo, int hi) {
        TreeNode* dummy=new TreeNode(INT_MAX);
        dummy->left=root;
        trim(dummy,lo,hi);
        return dummy->left;
    }
};
// Function to print the tree in-order (LNR - Left, Node, Right)
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Helper function to insert a new node into the BST
TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) return new TreeNode(key);
    if (key < root->val) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

int main() {
    Solution sol;

    // Constructing a binary search tree
    TreeNode* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "In-order traversal of the tree before trimming: ";
    inorder(root);
    cout << endl;

    int lo = 30, hi = 70;
    root = sol.trimBST(root, lo, hi);

    cout << "In-order traversal of the tree after trimming [" << lo << ", " << hi << "]: ";
    inorder(root);
    cout << endl;

    return 0;
}