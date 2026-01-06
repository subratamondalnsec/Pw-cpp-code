#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
TreeNode* predecessor(TreeNode* root, int key){
    if(root->left==NULL) return NULL;
    TreeNode* pred=root->left;
    while(pred->right!=NULL)  pred=pred->right;
    return pred;
}
TreeNode* successor(TreeNode* root, int key){
    if(root->right==NULL) return NULL;
    TreeNode* pred=root->right;
    while(pred->left!=NULL)  pred=pred->left;
    return pred;
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
/*      10
       /  \
      5    15
     / \     \
    3   7    18
*/
    int key=10;
    cout<<predecessor(root,key)->val<<endl;
    cout<<successor(root,key)->val<<endl;
    return 0;
}