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
    TreeNode* solve(TreeNode* node, int val)
    {
        if(node==NULL)
        return NULL;
        
        if(node!=NULL and node->val==val)
        return node;

        if(val < node->val)
        return solve(node->left,val);

        return solve(node->right,val);
    }

    TreeNode* searchBST(TreeNode* root, int val) 
    {
        return solve(root,val);    
    }
};
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val){
        if(root==NULL || root->val==val) return root;
        else if(root->val > val) return searchBST(root->left,val);
        else return searchBST(root->right,val);
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
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);

    // Search for a value in the BST
    int val = 2;
    TreeNode* result = solution.searchBST(root, val);

    if (result != NULL)
        std::cout << "Node found with value: " << result->val << std::endl;
    else
        std::cout << "Node not found" << std::endl;

    // Print the BST inorder (for verification purposes)
    std::cout << "Output of the BST: ";
    printLevelOrder(result);
    std::cout << std::endl;

    return 0;
}