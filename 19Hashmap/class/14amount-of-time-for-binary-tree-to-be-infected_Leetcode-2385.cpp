#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
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
    TreeNode* first = NULL;
    
    // Mark each node's parent in a map
    void markparent(unordered_map<TreeNode*, TreeNode*> &parent, TreeNode* root) {
        if (root == NULL) return;
        if (root->left) parent[root->left] = root;
        if (root->right) parent[root->right] = root;
        markparent(parent, root->left);
        markparent(parent, root->right);
    }

    // Find the start node
    void find(TreeNode* root, int start) {
        if (root == NULL) return;
        if (root->val == start) {
            first = root;
            return;
        }
        if (root->left) find(root->left, start);
        if (root->right) find(root->right, start);
    }

    // Function to calculate the time taken to infect the entire tree
    int amountOfTime(TreeNode* root, int start) {
        find(root, start);
        unordered_map<TreeNode*, TreeNode*> parent;
        markparent(parent, root);
        unordered_set<TreeNode*> visited;
        visited.insert(first);
        queue<pair<TreeNode*, int>> q;
        int maxlevel = 0;
        q.push({first, 0});

        while (!q.empty()) {
            TreeNode* temp = q.front().first;
            int level = q.front().second;
            q.pop();
            maxlevel = max(level, maxlevel);

            if (temp->left && visited.find(temp->left) == visited.end()) {
                q.push({temp->left, level + 1});
                visited.insert(temp->left);
            }
            if (temp->right && visited.find(temp->right) == visited.end()) {
                q.push({temp->right, level + 1});
                visited.insert(temp->right);
            }
            if (parent.find(temp) != parent.end() && visited.find(parent[temp]) == visited.end()) {
                q.push({parent[temp], level + 1});
                visited.insert(parent[temp]);
            }
        }
        return maxlevel;
    }
};

// Main function for testing
int main() {
    Solution solution;

    // Constructing a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Start infection from node 3
    int start = 3;

    // Calculating the time to infect the entire tree
    int time = solution.amountOfTime(root, start);
    
    // Printing the result
    cout << "Time taken to infect the entire tree: " << time << endl;

    return 0;
}
