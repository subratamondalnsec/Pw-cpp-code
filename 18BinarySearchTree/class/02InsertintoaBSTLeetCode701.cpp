#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*class Solution { //m1
public:
    void insert(TreeNode* root, int val){
        if(root==NULL) root= new TreeNode(val);
        else if(root->val>  val){//go left
            if(root->left == NULL) {
                root->left=new TreeNode(val);
            }
            else insertIntoBST( root->left, val);
        }
        else{//go right
             if(root->right == NULL) {
                root->right=new TreeNode(val);
            }
            else insertIntoBST( root->right, val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insert(root,val);
        if(root==NULL) return new TreeNode(val);
        return root;
    }
};*/

// class Solution {//m2
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         if(root==NULL) return new TreeNode(val);
//         else if(root->val>  val){//go left
//             if(root->left == NULL) {
//                 root->left=new TreeNode(val);
//             }
//             else insertIntoBST( root->left, val);
//         }
//         else{//go right
//              if(root->right == NULL) {
//                 root->right=new TreeNode(val);
//             }
//             else insertIntoBST( root->right, val);
//         }
//         return root;
//     }
// };

class Solution {//m3
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       if (root == NULL) return new TreeNode(val);
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

// Helper function to insert nodes into the BST
TreeNode* insert(TreeNode* node, int val) {
    if (node == NULL)
        return new TreeNode(val);

    if (val < node->val)
        node->left = insert(node->left, val);
    else
        node->right = insert(node->right, val);

    return node;
}


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
    Solution sol;
 // Create the BST
    TreeNode* root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);
    cout << "input of BST: ";
    printLevelOrder(root);
    root = sol.insertIntoBST(root, 5);
    // Display the BST using inorder traversal
    
    cout << "output of BST: ";
    printLevelOrder(root);
    cout << endl;
    
    return 0;
}
