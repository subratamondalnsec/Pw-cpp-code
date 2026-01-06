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
    void helper(TreeNode *root,int level,unordered_map<int,int>& map){
        if(root==nullptr) return;
        map[level]=root->val;
        helper(root->right,level+1,map);
        helper(root->left,level+1,map);
    }
    vector<int>leftSideView(TreeNode *root){
        if(root==nullptr) return {};
        unordered_map<int,int>map;
        helper(root,0,map);
        vector<int>ans;
        for(int i=0;i<map.size();i++) ans.push_back(map[i]);
        return ans;
    }
};

// Helper function to insert nodes in the binary tree for demonstration.
TreeNode* insertLevelOrder(vector<int> arr, int i, int n) {
    TreeNode* root = nullptr;
    if (i < n) {
        root = new TreeNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

int main() {
    // Example usage:
    vector<int> nodes = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = insertLevelOrder(nodes, 0, nodes.size());

    Solution sol;
    vector<int> result = sol.leftSideView(root);

    // Print the result.
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}