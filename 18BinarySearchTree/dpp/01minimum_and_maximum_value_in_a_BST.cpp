#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int minimum(TreeNode* root){
    if(root==NULL) return INT_MAX;
    return min(root->val,minimum(root->left));
}
int maximum(TreeNode* root){
    if(root==NULL) return INT_MIN;
    return max(root->val,maximum(root->right));
}

// int minimum(TreeNode* root){
//     if(root==NULL) return INT_MAX;
//     return min(root->val,min(minimum(root->left),minimum(root->right)));
// }
// int maximum(TreeNode* root){
//     if(root==NULL) return INT_MIN;
//     return max(root->val,max(maximum(root->left),maximum(root->right)));
// }
// Helper function to insert nodes into the BST
TreeNode* insert(TreeNode* node, int val) {
    if (node == NULL) return new TreeNode(val);
    if (val < node->val) node->left = insert(node->left, val);
    else node->right = insert(node->right, val);
    return node;
}

int main() {
    // Create the BST
    TreeNode* root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);
    cout<<"minimum value of BST : "<<minimum(root)<<endl;
    cout<<"maximum value of BST : "<<maximum(root);
}