#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*class Solution {//same as 236 same code
public:
    bool exists(TreeNode* root, TreeNode* target){
        if(root==NULL) return false;
        if (root==target) return true;
        return exists(root->left, target) || exists(root->right, target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(exists(root->left, p) && exists(root->left, q)) return lowestCommonAncestor(root->left, p, q);
            else if(exists(root->right, p) && exists(root->right, q)) return lowestCommonAncestor (root->right, p, q);
            return root;
    }
};*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q); 
        else if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left,p,q);
        else return root; 
    }  
};

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//             if(root->val==p->val || root->val == q->val) return root;
//             else if(root->val > p->val && root->val < q->val) return root;
//             else if(root->val < p->val && root->val > q->val) return root; 
//             else if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q); 
//             else return lowestCommonAncestor(root->left,p,q); 
//     }
// };

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

    // Create the binary tree
    TreeNode* root = NULL;
    root = insert(root, 4);
    TreeNode* node2 = insert(root, 2);
    insert(root, 7);
    TreeNode* node1 = insert(root, 1);
    TreeNode* node3 = insert(root, 3);
// Print the binary tree inorder (for verification purposes)
    std::cout << "Input of the binary tree: ";
    printLevelOrder(root);
    cout << endl;
    // Find the lowest common ancestor of two nodes
    TreeNode* result = solution.lowestCommonAncestor(root, node1, node3);

    if (result != NULL)
        std::cout << "Lowest Common Ancestor: " << result->val << std::endl;
    else
        std::cout << "Lowest Common Ancestor not found" << std::endl;

    

    return 0;
}