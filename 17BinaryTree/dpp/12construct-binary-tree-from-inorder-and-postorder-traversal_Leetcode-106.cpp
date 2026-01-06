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
    TreeNode* build(vector<int>& in,int inlo ,int inhi, vector<int>& post,int postlo,int posthi) {
        if(postlo>posthi) return NULL;
        TreeNode* root=new TreeNode(post[posthi]);
        if(postlo==posthi) return root;
        int i= inlo;
        while(i<=inhi){
            if(in[i]==post[posthi]) break;
            i++;
        }
        int leftcount=i-inlo;
        int rightcout=inhi-i;
        root->left=build(in,inlo,i-1,post,postlo,postlo+leftcount-1);
        root->right=build(in,i+1,inhi,post,postlo+leftcount,posthi-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n=in.size();
        return build(in,0,n-1,post,0,n-1);
    }
};

// Function to print the tree in preorder to verify correctness
void preorderPrint(TreeNode* root) {
    if(root == NULL) return;
    cout << root->val << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main() {
    // Input arrays
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    // Create the solution object
    Solution sol;

    // Build the tree
    TreeNode* root = sol.buildTree(inorder, postorder);

    // Print the tree using preorder traversal
    cout << "Preorder traversal of the constructed tree: ";
    preorderPrint(root);
    cout << endl;

    return 0;
}