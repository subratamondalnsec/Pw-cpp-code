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
    TreeNode* iop(TreeNode* root){
        TreeNode* pred=root->left;
        while(pred->right!=NULL)  pred=pred->right;
        return pred;
    }
    TreeNode* ios(TreeNode* root){
        TreeNode* suc=root->right;
        while(suc->left!=NULL)  suc=suc->left;
        return suc;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            //case 1: 0 child node
            if(root->left==NULL && root->right==NULL) return NULL;

            //case 2: 1 child node
            if(root->left==NULL || root->right==NULL){
                if(root->left!=NULL) return root->left;
                else return root->right;
            }

            // //case 3: 2 child node
            // if(root->left!=NULL && root->right!=NULL){
            //    TreeNode* pred=iop(root);//predessor 
            //    root->val=pred->val;
            //    root->left= deleteNode(root->left,pred->val);
            // }

            //case 3: 2 child node
            if(root->left!=NULL && root->right!=NULL){
               TreeNode* suc=ios(root);//predessor 
               root->val=suc->val;
               root->right= deleteNode(root->right,suc->val);
            }
        }
        else if(root->val > key) root->left=deleteNode(root->left,key);
        else root->right=deleteNode(root->right,key);
        return root;
    }
};

// Function to print the tree in-order (LNR - Left, Node, Right)
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Helper function to insert a new node into the BST
TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) return new TreeNode(key);
    if (key < root->val) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

int main() {
    Solution sol;

    // Constructing a binary search tree
    TreeNode* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "In-order traversal of the tree before deletion: ";
    inorder(root);
    cout << endl;

    int key = 50;
    root = sol.deleteNode(root, key);

    cout << "In-order traversal of the tree after deletion of " << key << ": ";
    inorder(root);
    cout << endl;

    return 0;
}