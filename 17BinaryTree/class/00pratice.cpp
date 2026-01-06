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
    TreeNode* build(vector<int>& pre,int prelo,int prehi,vector<int>& in,int inlo ,int inhi) {
        if(prelo>prehi) return NULL;
        TreeNode* root= new TreeNode(pre[prelo]);
        if(prelo==prehi) return root;
        int i=inlo;
        while(i<=inhi){
            if(in[i]==pre[prelo]) break;
            i++;
        }
        int leftcount=i-inlo;
        int rightcount=inhi-i;
        root->left=build(pre,prelo+1,prelo+leftcount,in,inlo,i-1);
        root->right=build(pre,prelo+leftcount+1,prehi,in,i+1,inhi);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();
        return build(pre,0,n-1,in,0,n-1);
    }
};

// Helper function to print the tree in level order (for demonstration).
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

int main() {
    // Example usage:
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    // Print the result (level order traversal).
    printLevelOrder(root);

    return 0;
}