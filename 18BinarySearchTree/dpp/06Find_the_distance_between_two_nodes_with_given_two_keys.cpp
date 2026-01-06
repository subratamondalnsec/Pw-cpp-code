//Given a BST and two keys in it. Find the distance between two nodes with given two keys. It may be assumed that both keys exist in BST
#include <bits/stdc++.h>
using namespace std;
struct Node {
	struct Node* left, *right;
	int key;
};

struct Node* newNode(int key)
{
	struct Node* ptr = new Node;
	ptr->key = key;
	ptr->left = ptr->right = NULL;
	return ptr;
}

// Standard BST insert function
struct Node* insert(struct Node* root, int key)
{
	if (!root)
		root = newNode(key);
	else if (root->key > key)
		root->left = insert(root->left, key);
	else if (root->key < key)
		root->right = insert(root->right, key);
	return root;
}
int distanceFromRoot(struct Node* root, int x){
    if(!root) return 0;
	if (root->key == x) return 0;
	if (root->key > x) return 1 + distanceFromRoot(root->left, x);
	return 1 + distanceFromRoot(root->right, x);
}

// Returns minimum distance between a and b.
// This function assumes that a and b exist
// in BST.
int distanceBetween2(struct Node* root, int a, int b){
	if (!root) return 0;
	// Both keys lie in left
	if (root->key > a && root->key > b) return distanceBetween2(root->left, a, b);
	// Both keys lie in right
	if (root->key < a && root->key < b)return distanceBetween2(root->right, a, b);
	// Lie in opposite directions (Root is LCA of two nodes)
	if (root->key >= a && root->key <= b)return distanceFromRoot(root, a) + distanceFromRoot(root, b);
}
int main()
{
	struct Node* root = NULL;
	root = insert(root, 20);
	insert(root, 10);
	insert(root, 5);
	insert(root, 15);
	insert(root, 30);
	insert(root, 25);
	insert(root, 35);
	int a = 5, b = 55;
    if(a>b) swap(a,b);
	cout << distanceBetween2(root, a, b);
	return 0;
}

