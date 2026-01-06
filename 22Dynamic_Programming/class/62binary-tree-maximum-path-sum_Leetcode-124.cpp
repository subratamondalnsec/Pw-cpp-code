#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int helper(TreeNode* root ,int & ans){
        if(root==NULL) return 0;
        int leftsum=helper(root->left,ans);
        int rightsum=helper(root->right,ans);
        int maxsum=root->val;
        if(leftsum>0) maxsum+=leftsum;
        if(rightsum>0) maxsum+=rightsum;
        ans=max(ans,maxsum);
        return max(root->val,root->val+max(leftsum,rightsum));
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        helper(root,ans);
        return ans;
    }
};

int main() {
    // Creating a sample binary tree
    //      -10
    //      / \
    //     9  20
    //       / \
    //      15   7
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    int path = solution.maxPathSum(root);
    cout << " The maximum path sum of binary tree is: " << path << endl;

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}