#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*class Solution {//bekar method
public:
    long long maxTree(TreeNode* root){
        if(root==NULL) return LLONG_MIN; 
        return max((long long)(root->val), max(maxTree(root->left),maxTree(root->right)));
    }
    long long minTree(TreeNode* root){
        if(root==NULL) return LLONG_MAX; 
        return min((long long)(root->val), min(minTree(root->left),minTree(root->right)));
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        else if((long long)(root->val) <= maxTree(root->left)) return false;
        else if((long long)(root->val)>= minTree(root->right)) return false ;
        return (isValidBST(root->left) && isValidBST (root->right));
    }
};*/

// class Solution {//m2
// public:
//     void inorder (TreeNode* root, vector<int>& ans) {
//         if(root==NULL) return; // base case
//         inorder(root->left, ans); // left 
//         ans.push_back(root->val); // root
//         inorder(root->right, ans); // right
//     }
//     bool isValidBST(TreeNode* root) {
//         vector<int> ans;
//         inorder(root, ans);
//         for(int i=1;i<ans.size();i++){
//             if (ans [i]<=ans [i-1]) return false;
//         }
//         return true;
//     }
// };

/*class Solution {//m3
public:
    TreeNode* prev=NULL;
    bool flag =true;
    void inorder (TreeNode* root) { 
        if(root==NULL) return; // base case
        inorder(root->left); // left 
        if(prev!=NULL){
            if(root->val <=prev->val){
                flag=false;
                return;
            }
       }
       prev=root;
        inorder(root->right); // right
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return flag;
    }
};*/

class Solution {//m4
public:
    void inorder (TreeNode* root,TreeNode* &prev,bool &flag) {
        if(root==NULL) return; // base case
        inorder(root->left,prev,flag); // left 
        if(prev!=NULL){
            if(root->val <=prev->val){
                flag=false;
                return;
            }
        }
        prev=root;
        inorder(root->right,prev,flag); // right
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev=NULL;
        bool flag =true;
        inorder(root,prev,flag);
        return flag;
    }
};

// Helper function to insert nodes into the binary tree
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
    Solution solution;

    // Create the binary tree
    TreeNode* root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    insert(root, 7);

// Print the binary tree inorder (for verification purposes)
    cout << "Input of the binary tree: ";
    printLevelOrder(root);
    cout << endl;

    // Check if the tree is a valid BST
    bool isValid = solution.isValidBST(root);
    if (isValid)
        std::cout << "The tree is a valid BST" << std::endl;
    else
        std::cout << "The tree is not a valid BST" << std::endl;
    return 0;
}
