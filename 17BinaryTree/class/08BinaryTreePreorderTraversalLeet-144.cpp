#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*class Solution {//RECURSION
public:
    void preorder(TreeNode *root, vector<int>& ans) {
        if (root == NULL) return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};*/

class Solution {//iterative
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root!=NULL) st.push(root);
        while(st.size()>0){
            TreeNode* temp =st.top();
            st.pop();
            ans.push_back(temp-> val);
            if(temp->right!=NULL) st.push(temp->right);
            if(temp->left!=NULL) st.push(temp->left);
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
    vector<int> result = solution.preorderTraversal(root);

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
