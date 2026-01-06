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
int levels(Node* root){
    if(root==NULL) return 0;
    return 1+ max(levels(root->left),levels(root->right));
}
void Nthlevel(Node* root,int curr,int level){
    if(root==NULL) return;
    if(curr==level){
        cout<<root->val<<" ";
        return ;
    }
    Nthlevel(root->left,curr+1,level);
    Nthlevel(root->right,curr+1,level);
}
void levelorder(Node* root){
    int n=levels(root);
    for(int i=0;i<=n;i++){
        Nthlevel(root,1,i);
        cout<<endl;
    }
}
void Nthlevelrev(Node* root,int curr,int level){
    if(root==NULL) return;
    if(curr==level){
        cout<<root->val<<" ";
        return ;
    }
    Nthlevelrev(root->right,curr+1,level);
    Nthlevelrev(root->left,curr+1,level);
}
void levelorderrev(Node* root){
    int n=levels(root);
    for(int i=0;i<=n;i++){
        Nthlevelrev(root,1,i);
        cout<<endl;
    }
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
    // Creating a sample binary tree
    //       1
    //     /   \
    //   2      3
    //  / \    / \
    // 4   5  6   7
    //    / \
    //   8  12

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    e->left=h;
    e->right=i;
    int level=1;
    levelorder(a);
    levelorderrev(a);
}