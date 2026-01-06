#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void helper(TreeNode* root, int targetSum,bool &flag){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
           if(root->val==targetSum){
                flag= true;
                return;
            } 
            return;
        }
        helper(root->left,targetSum-(root->val),flag);
        helper(root->right,targetSum-(root->val),flag);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        bool flag=false;
        helper(root,targetSum,flag);
        return flag;
    }
};
// Function to insert nodes in level order
TreeNode* insertLevelOrder(int arr[], int i, int n) {
    TreeNode* root = NULL;
    // Base case for recursion
    if (i < n) {
        root = new TreeNode(arr[i]);
        // insert left child
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        // insert right child
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

int main() {
    // Example array representing level order traversal of a tree
    int arr[] = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1}; // -1 represents null nodes
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode* root = insertLevelOrder(arr, 0, n);

    Solution solution;
    int targetSum = 22;
    
    if (solution.hasPathSum(root, targetSum)) {
        cout << "There is a root-to-leaf path with sum " << targetSum << endl;
    } else {
        cout << "There is no root-to-leaf path with sum " << targetSum << endl;
    }

    return 0;
}
