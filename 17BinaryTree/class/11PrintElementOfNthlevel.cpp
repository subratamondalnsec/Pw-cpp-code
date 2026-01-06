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
void Nthlevelelement(Node *root,int level){
    if(root==NULL) return;
    if(level==0){ 
    cout<<root->val<<"  ";
    return;
    }
    Nthlevelelement(root->left,level-1);
    Nthlevelelement(root->right,level-1);
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
    int level=4;
    Nthlevelelement(a,level-1);
}