#include <bits/stdc++.h>
using namespace std;
class Node{// this is a tree node
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void displayTree(Node *root){
    if(root==NULL) return;
    cout<<root->val<<"  ";
    displayTree(root->left);
    displayTree(root->right);
}
int sum(Node *root){
    if(root==NULL) return 0;
    return root->val+sum(root->left)+sum(root->right);
}
int size(Node *root){
    if(root==NULL) return 0;
    return (1+size(root->left)+size(root->right));
}
int maxInTree(Node *root){
    if(root==NULL) return INT_MIN;
    return max(root->val,max(maxInTree(root->left),maxInTree(root->right)));
}
int level(Node *root){
    if(root==NULL) return 0;
    return (1+max(level(root->left),level(root->right)));
}
int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(4);
    Node *e=new Node(5);
    Node *f=new Node(6);
    Node *g=new Node(7);
    Node *h=new Node(8);
    Node *i=new Node(12);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    e->left=h;
    e->right=i;
    displayTree(a);
    cout<<endl<<sum(a);
    cout<<endl<<size(a);
    cout<<endl<<maxInTree(a);
    cout<<endl<<level(a);
}