#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {//optimized apporch
public:
    void inorder(TreeNode* root,int& k,int& ans){
        if(root==NULL) return;
        inorder(root->left,k,ans);
        if(--k==0){
            ans=root->val;
            return;
        }
        inorder(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        inorder(root,k,ans);
        return ans;
    }
};

class Solution {
public:
    void inorder(TreeNode* root,vector<int>& ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        inorder(root,ans);
        return ans[k-1];
    }
};
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
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 1);

    // Create an object of Solution class
    Solution sol;

    // Find the 3rd smallest element in the BST
    int k = 3;
    int result = sol.kthSmallest(root, k);

    // Print the result
    cout << "The " << k << "rd smallest element is " << result << endl;

    return 0;
}
