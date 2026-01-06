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
void preorder(Node *root){//preorder
    if(root==NULL) return;
    cout<<root->val<<"  ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root){//inorder
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<"  ";
    inorder(root->right);
}
void postorder(Node *root){//postorder
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<"  ";
}
int main(){
    Node *a=new Node(1);
    Node *b=new Node(2);
    Node *c=new Node(3);
    Node *d=new Node(4);
    Node *e=new Node(5);
    Node *f=new Node(6);
    Node *g=new Node(7);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    preorder(a);
    cout<<endl; 
    inorder(a);
    cout<<endl; 
    postorder(a);
    cout<<endl; 
}