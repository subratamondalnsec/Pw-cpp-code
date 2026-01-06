#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if (p!=NULL && q==NULL) return false;

        if(p->val != q->val) return false;
        bool leftAns = isSameTree(p->left, q->left);

        if(leftAns==false) return false;
        bool rightAns = isSameTree(p->right, q->right);
        
        if (rightAns==false) return false;
        return true;
    }
};*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;

        if(p->val != q->val) return false;
        bool leftAns = isSameTree(p->left, q->left);

        if(leftAns==false) return false;
        bool rightAns = isSameTree(p->right, q->right);
        
        if (rightAns==false) return false;
        return true;
    }
};

int main() {
    // Creating first binary tree
    //        1
    //       / \
    //      2   3
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Creating second binary tree
    //        1
    //       / \
    //      2   3
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution solution;
    bool result = solution.isSameTree(p, q);

    if (result) {
        cout << "The trees are the same." << endl;
    } else {
        cout << "The trees are not the same." << endl;
    }

    // Clean up memory
    delete p->left;
    delete p->right;
    delete p;
    delete q->left;
    delete q->right;
    delete q;

    return 0;
}