#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(level(root->left),level(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int lefttree=level(root->left);
        int righttree=level(root->right);
        int diff=abs(lefttree-righttree);
        if(diff>1)  return false;

        bool lefttreeans=isBalanced( root->left);
        if(lefttreeans==false) return false;

        bool righttreeans= isBalanced( root->right);
        if(righttreeans==false) return false;
        
        return true;
    }
};

// Main function to test the isBalanced function
int main() {
    // Create a sample tree:
    //        1
    //       / \
    //      2   3
    //     /
    //    4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution sol;
    if (sol.isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}