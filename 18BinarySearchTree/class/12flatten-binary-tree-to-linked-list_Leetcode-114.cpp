#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {//m1
public:
    void preorder(TreeNode *root, vector<TreeNode*>& ans){//preorder
        if(root==NULL) return;
        ans.push_back(root);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> ans;
        preorder(root,ans);
        int n=ans.size();
        for(int i=0;i<n-1;i++){
            ans[i]->right=ans[i+1];
            ans[i]->left=NULL;
        }
    }
};

class Solution {//m2
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* l= root->left;
        TreeNode* r= root->right;
        root->right=NULL;
        root->left=NULL;
        flatten(l);
        flatten(r);
        root->right=l;
        TreeNode* temp= root;
        while(temp->right!=NULL) temp=temp->right;
        temp->right=r;
    }
};
class Solution {//m3
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* curr= root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                TreeNode* r = curr->right;
                curr->right=curr->left;
                TreeNode* pred = curr->left;
                while(pred->right!=NULL) pred=pred->right;
                pred->right=r;
                curr=curr->left;
            }
            else  curr=curr->right;
        }
        TreeNode* temp= root;
        while(temp->right!=NULL){
            temp->left=NULL;
            temp=temp->right;
        }
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    // Create an object of Solution class
    Solution sol;

    // Call the flatten function
    sol.flatten(root);

    // Traverse the flattened tree and print values
    TreeNode* curr = root;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->right;
    }

    return 0;
}
