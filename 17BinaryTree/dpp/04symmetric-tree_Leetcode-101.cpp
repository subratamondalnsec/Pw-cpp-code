#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {//DFS
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;

        if(p->val != q->val) return false;

        bool leftAns = isSameTree(p->left, q->left);
        if(leftAns==false) return false;

        bool rightAns = isSameTree(p->right, q->right);
        if (rightAns==false) return false;

        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        invertTree(root->left);
        bool flag=isSameTree(root->left,root->right);
        invertTree(root->left);
        return flag;
    }
};

class Solution {//BFS
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *>q1;
        queue<TreeNode *>q2;
        q1.push(root->left);
        q2.push(root->right);
        while(q1.size()>0 && q2.size()>0){
            TreeNode* p=q1.front();
            q1.pop();
            TreeNode* q=q2.front();
            q2.pop();
            if(p==NULL && q==NULL) continue;
            if(p==NULL || q==NULL) return false;
            if(p->val != q->val) return false;

            q1.push(p->left);
            q1.push(p->right);

            q2.push(q->right);
            q2.push(q->left);
        }
        return true;
    }
};

// Main function to test the isSymmetric function
int main() {
    // Create a sample symmetric tree:
    //        1
    //       / \
    //      2   2
    //     /     \
    //    3       3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(3);

    Solution sol;
    if (sol.isSymmetric(root)) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    return 0;
}