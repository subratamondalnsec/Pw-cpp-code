#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {//T.c=O(n)-> bottom to top
public:
    int ans=0;
    int diameter(TreeNode* root){
        if(root==NULL) return 0;
        int leftans=diameter(root->left);
        int rightans=diameter(root->right);
        ans=max(ans,(leftans+rightans+1));
        return 1+max(leftans,rightans);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return ans-1;
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