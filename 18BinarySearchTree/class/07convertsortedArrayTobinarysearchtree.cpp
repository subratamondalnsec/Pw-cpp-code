#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*class Solution {
public:
 void insert(TreeNode* root, int val){
         if(root==NULL) root= new TreeNode(val);
        else if(root->val>  val){//go left
            if(root->left == NULL) {
                root->left=new TreeNode(val);
            }
            else insert( root->left, val);
        }
        else{//go right
             if(root->right == NULL) {
                root->right=new TreeNode(val);
            }
            else insert( root->right, val);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root = new TreeNode (pre [0]);
        for(int i=1;i<pre.size();i++){
        insert(root, pre[i]);
        }
        return root;
    }
};*/

class Solution {
public:
    TreeNode* build (vector<int>& pre, int prelo, int prehi, vector<int>& in, int inlo, int inhi) {
        if (prelo>prehi) return NULL;
        TreeNode* root = new TreeNode (pre [prelo]);
        if(prelo==prehi) return root;
        int i = inlo;
        while(i<=inhi){
            if(in [i]==pre[prelo]) break;
            i++;
        }
        int leftCount = i -inlo;
        int rightCount = inhi -i;
        root->left = build(pre, prelo+1, prelo+leftCount, in, inlo, i-1);
        root->right = build(pre, prelo+leftCount+1, prehi, in, i+1, inhi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        vector<int> in = pre; // copy ban gayi
        sort(in.begin(),in.end());
        int n = pre.size();
        return build (pre, 0, n-1, in,0,n-1);
    }
};

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

    // Sorted array
    vector<int> preorder = { 8,5,1,7,10,12 };

    // Convert sorted array to BST
    TreeNode* root = solution.bstFromPreorder(preorder);

    // Print the BST inorder (for verification purposes)
    std::cout << "Output of the BST: ";
    printLevelOrder(root);
    std::cout << std::endl;

    return 0;
}
