#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     int levels(TreeNode* root){
//         if(root==NULL) return 0;
//         return 1+max(levels(root->left),levels(root->right));
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root==NULL) return 0;
//         return max({levels(root->left)+levels(root->right),diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)});
        
//     }
// };

// class Solution {
// public:
//     unordered_map<TreeNode*,int> mp;
//     int levels(TreeNode* root){
//         if(root==NULL) return 0;
//         if(mp.find(root)!=mp.end()) return mp[root];
//         return mp[root]= 1+max(levels(root->left),levels(root->right));
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root==NULL) return 0;
//         return max({levels(root->left)+levels(root->right),diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)});
        
//     }
// };

class Solution {
public:
    int ans;
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        int leftans=levels(root->left);
        int rightans=levels(root->right);
        int myans=leftans+rightans;
        ans=max(ans,myans);
        return 1+max(leftans,rightans);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        levels(root);
        return ans;
    }
};

int main() {
    // Creating a sample binary tree
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    //  /    /
    // 6     8
    //       \
    //        10

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->left->right->left = new TreeNode(8);
    root->left->right->left->right = new TreeNode(10);

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