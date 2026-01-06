#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int level(TreeNode *root){
        if(root==NULL) return 0;
        return (1+max(level(root->left),level(root->right)));
    }
    void NthlevelelementLtoR(TreeNode *root,int level,vector<int>& v){
        if(root==NULL) return;
        if(level==0){ 
        v.push_back(root->val);
        return;
        }// A ar inoder postorder  korlao same hobe
        NthlevelelementLtoR(root->left,level-1,v);
        NthlevelelementLtoR(root->right,level-1,v);
    }
    void NthlevelelementRtoL(TreeNode *root,int level,vector<int>& v){
        if(root==NULL) return;
        if(level==0){ 
        v.push_back(root->val);
        return;
        }// A ar inoder postorder  korlao same hobe
        NthlevelelementRtoL(root->right,level-1,v);
        NthlevelelementRtoL(root->left,level-1,v);
    }
    void levelorderLtoR(TreeNode *root,vector<vector<int>>& ans){
        int n=level(root);
        for(int i=1;i<=n;i++){
            vector<int> v;
            if(i%2==0) NthlevelelementRtoL(root,i-1,v);
            else NthlevelelementLtoR(root,i-1,v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root){
        vector<vector<int>> ans;
        levelorderLtoR(root,ans);
        return ans;
    }
};

// Helper function to insert nodes in the binary tree.
TreeNode* insertLevelOrder(vector<int> arr, int i) {
    if (i < arr.size()) {
        TreeNode *root = new TreeNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1);
        root->right = insertLevelOrder(arr, 2 * i + 2);
        return root;
    }
    return NULL;
}

int main() {
    // Example: creating a binary tree from level order array representation
    vector<int> arr = {3, 9, 20, -1, -1, 15, 7}; // -1 represents null node
    TreeNode *root = insertLevelOrder(arr, 0);

    // Create solution object and call the zigzag level order function
    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    // Print the result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}