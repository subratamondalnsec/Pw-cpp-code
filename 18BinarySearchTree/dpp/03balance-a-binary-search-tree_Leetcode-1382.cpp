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
    void inorder(TreeNode* root,vector<int>& ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode* helper(vector<int>& ans,int lo,int hi){
        if(lo>hi) return NULL;
        int mid=lo+(hi-lo)/2;
        TreeNode* root=new TreeNode(ans[mid]);
        root->left=helper(ans,lo,mid-1);
        root->right=helper(ans,mid+1,hi);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        int n=ans.size();
        return helper(ans,0,n-1);
    }
};

// Utility function to print the inorder traversal of the tree
void printInOrder(TreeNode* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

// Function to insert a new node in a binary search tree
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
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);

    // Print inorder traversal of the original unbalanced tree
    cout << "Original InOrder: ";
    printInOrder(root);
    cout << endl;

    // Create an object of Solution class
    Solution sol;

    // Balance the BST
    TreeNode* balancedRoot = sol.balanceBST(root);

    // Print inorder traversal of the balanced tree
    cout << "Balanced InOrder: ";
    printInOrder(balancedRoot);
    cout << endl;

    return 0;
}