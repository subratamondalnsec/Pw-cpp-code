#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {//recursion
public:
    void postorder(TreeNode *root, vector<int>& ans) {
        if (root == NULL) return;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};

class Solution {//iterative
public:
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> ans;
        stack<TreeNode*> st;
        if(root!=NULL) st.push(root);
        while(st.size()>0){
            TreeNode* temp =st.top();
            st.pop();
            ans.push_back(temp-> val);
            if(temp->left!=NULL) st.push(temp->left);
            if(temp->right!=NULL) st.push(temp->right);
        }
        reverse(ans.begin(),ans.end());
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
    vector<int> result = solution.postorderTraversal(root);

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
