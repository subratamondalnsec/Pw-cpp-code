#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution { //recursion
public:
    void inorder(TreeNode *root, vector<int>& ans) {
        if (root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

class Solution {//iterative 
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
       stack<TreeNode*>st;
       TreeNode* node= root;
       while(st.size()>0 || node!=NULL){
            if(node){
                st.push(node);
                node=node->left;
            }
            else{
                TreeNode* temp=st.top();
                st.pop();
                ans.push_back(temp->val);
                node=temp-> right;
            }
        }
        return ans;
    }
};

int main() {
    // Create a sample tree:
    //      1
    //       \
    //        2
    //       /
    //      3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Cleanup
    delete root->right->left;
    delete root->right;
    delete root;
    
    return 0;
}
