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
    TreeNode* build(vector<int>& pre,int prelo,int prehi, vector<int>& post,int postlo,int posthi){
        if(prelo>prehi) return NULL;
        TreeNode* root=new TreeNode(pre[prelo]);
        if(prelo==prehi) return root;
        int i=postlo;
        while(i<=posthi){
            if(post[i]==pre[prelo+1]) break;
            i++;
        }
        int leftcount=i+1-postlo;
        int rightcount=posthi-i-1;
        root->left=build(pre,prelo+1,prelo+leftcount,post,postlo,i);
        root->right=build(pre,prelo+leftcount+1,prehi,post,i+1,posthi-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n=pre.size();
        return build(pre,0,n-1,post,0,n-1);
    }
};

// Function to print the tree in inorder traversal for verification
void inorderPrint(TreeNode* root) {
    if (root == NULL) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main() {
    // Input arrays
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

    // Create the solution object
    Solution sol;

    // Build the tree
    TreeNode* root = sol.constructFromPrePost(preorder, postorder);

    // Print the tree using inorder traversal
    cout << "Inorder traversal of the constructed tree: ";
    inorderPrint(root);
    cout << endl;

    return 0;
}