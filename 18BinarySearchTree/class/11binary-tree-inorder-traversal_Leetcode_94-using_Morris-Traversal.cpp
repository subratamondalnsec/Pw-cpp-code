#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr= root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                TreeNode* preb= curr->left;
                while(preb->right!=NULL && preb->right!=curr){
                    preb=preb->right;
                }
                if(preb->right==NULL){//link
                    preb->right=curr;
                    curr=curr->left;
                }
                else{//preb->right==curr
                    preb->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
            else{
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
        return ans;
    }
};

int main() {
    // Create a sample tree: 
    //     1
    //      \
    //       2
    //      /
    //     3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    // Create solution object
    Solution solution;
    // Get the inorder traversal
    vector<int> result = solution.inorderTraversal(root);
    
    // Output the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory (optional)
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}