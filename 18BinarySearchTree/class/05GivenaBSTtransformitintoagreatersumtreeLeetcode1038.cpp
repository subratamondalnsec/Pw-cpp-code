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
     int sum = 0;
    void reverseInorder (TreeNode* root) {
        // right root left
        if(root==NULL) return;
        reverseInorder(root->right);
        root->val += sum;
        sum = root->val;
        reverseInorder (root->left);
    }   
    TreeNode* bstToGst(TreeNode* root) {
        reverseInorder(root);
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

// Helper function to print the tree inorder (for verification purposes)
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

    // Create the BST
    TreeNode* root = NULL;
    root = insert(root, 4);
    insert(root, 1);
    insert(root, 6);
    insert(root, 0);
    insert(root, 2);
    insert(root, 5);
    insert(root, 7);
    insert(root, 3);
    insert(root, 8);
    cout << "Input of the Greater Sum Tree: ";
    printLevelOrder(root);
    cout << endl;

    // Convert BST to GST
    solution.bstToGst(root);
    cout << "output of the Greater Sum Tree: ";
    printLevelOrder(root);
    cout << endl;
    return 0;
}