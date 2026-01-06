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
    bool exists(TreeNode* root, TreeNode* target){
        if(root==NULL) return false;
        if (root==target) return true;
        return exists(root->left, target) || exists(root->right, target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==p || root==q) return root;
        else if (exists(root->left, p) && exists(root->right, q)) return root;
        else if (exists(root->right, p) && exists(root->left, q)) return root;
        else if(exists(root->left, p) && exists(root->left, q)) return lowestCommonAncestor (root->left, p, q);
        else return lowestCommonAncestor (root->right, p, q);
    }
};

/*class Solution {
public:
    bool exists(TreeNode* root, TreeNode* target){
        if(root==NULL) return false;
        if (root==target) return true;
        return exists(root->left, target) || exists(root->right, target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(exists(root->left, p) && exists(root->left, q)) return lowestCommonAncestor(root->left, p, q);
            else if(exists(root->right, p) && exists(root->right, q)) return lowestCommonAncestor (root->right, p, q);
            return root;
    }
};*/

int main() {
    // Creating a sample binary tree
    //        3
    //       / \
    //      5   1
    //     / \ / \
    //    6  2 0  8
    //      / \
    //     7   4
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;        // Node 5
    TreeNode* q = root->left->right->right; // Node 4

    Solution solution;
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);

    if (lca != NULL) {
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    // Clean up memory
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
