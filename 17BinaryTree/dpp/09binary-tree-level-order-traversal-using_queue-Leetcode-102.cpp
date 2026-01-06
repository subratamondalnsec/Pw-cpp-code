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
    vector<vector<int>> levelOrder(TreeNode* root) {//using queue in bfs
        if(root==NULL) return{};//T.C=>O(n); S.C=>O(2^h) h=height of nodes
        vector<vector<int>> ans;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
            int size=q.size();
            vector<int>v(size);
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                v[i]=temp->val;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right !=NULL) q.push(temp->right); 
            }
            ans.push_back(v);
        }
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
    vector<vector<int>> result = sol.levelOrder(root);
    // Print the result.
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}