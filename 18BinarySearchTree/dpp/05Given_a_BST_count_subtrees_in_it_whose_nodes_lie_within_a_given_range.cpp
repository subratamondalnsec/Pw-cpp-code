// C++ program to count subtrees that lie in a given range 
#include <bits/stdc++.h> 
using namespace std; 
struct node { 
	int data; 
	struct node *left, *right; 
};  
bool getCountUtil(node* root, int low, int high, int& count) { 

	if (root == NULL) return true; 
	// Recur for left and right subtrees 
	bool l = getCountUtil(root->left, low, high, count); 
	bool r = getCountUtil(root->right, low, high, count); 

	// If both left and right subtrees are in range and current node 
	// is also in range, then increment count and return true 
	if (l && r &&(root->data >= low && root->data <= high) ) { 
		++count; 
		return true; 
	} 

	return false; 
} 
// Utility function to create new node 
node* newNode(int data) 
{ 
	node* temp = new node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return (temp); 
} 

// Driver program 
int main() 
{ 
	// Let us construct the BST shown in the above figure 
	node* root = newNode(10); 
	root->left = newNode(5); 
	root->right = newNode(50); 
	root->left->left = newNode(1); 
	root->right->left = newNode(40); 
	root->right->right = newNode(100); 
	/* Let us constructed BST shown in above example 
		10 
		/ \ 
	5	 50 
	/	 / \ 
	1	 40 100 */
	int l = 5; 
	int h = 45; 
    int count = 0;
    getCountUtil(root, l, h, count);
	cout << "Count of subtrees in [" << l << ", "<< h << "] is " << count; 
	return 0; 
} 
