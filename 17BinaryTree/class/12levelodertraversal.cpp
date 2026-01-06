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
int level(Node *root){
    if(root==NULL) return 0;
    return (1+max(level(root->left),level(root->right)));
}
void NthlevelelementLtoR(Node *root,int level){
    if(root==NULL) return;
    if(level==1){ 
    cout<<root->val<<"  ";
    return;
    }// A ar inoder postorder  korlao same hobe
    NthlevelelementLtoR(root->left,level-1);
    NthlevelelementLtoR(root->right,level-1);
}
void levelorderLtoR(Node *root){
    int n=level(root);
    for(int i=1;i<=n;i++){
        NthlevelelementLtoR(root,i);
        cout<<endl;
    }
}
void NthlevelelementRtoL(Node *root,int level){
    if(root==NULL) return;
    if(level==1){ 
    cout<<root->val<<"  ";
    return;
    }
    NthlevelelementRtoL(root->right,level-1);
    NthlevelelementRtoL(root->left,level-1);
}
void levelorderRtoL(Node *root){
    int n=level(root);
    for(int i=1;i<=n;i++){
        NthlevelelementRtoL(root,i);
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
    levelorderLtoR(a);
    levelorderRtoL(a);
}