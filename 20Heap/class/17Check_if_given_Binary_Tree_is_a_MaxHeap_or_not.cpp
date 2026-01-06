#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
bool isMax(Node* root){
    if(root==nullptr) return true;
    if(root->left!=nullptr && root->val < root->left->val) return false;
    if(root->right!=nullptr && root->val < root->right->val) return false;
    return isMax(root->left) && isMax(root->right);
}
int sizeofTree(Node* root){
    if(root==NULL) return 0;
    return 1+sizeofTree(root->left)+sizeofTree(root->right);
}
bool isCBT(Node* root){
    int size=sizeofTree(root);
    int count=0;
    queue<Node*>q;
    q.push(root);
    while(size>count){
        Node* temp=q.front();
        q.pop();
        count++;
        if(temp!=nullptr){
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    while(q.size()>0){
        Node* temp=q.front();
        q.pop();
        if(temp!=nullptr) return false;
    }
    return true;
}
int main(){
    Node *a=new Node(20);
    Node *b=new Node(15);
    Node *c=new Node(10);
    Node *d=new Node(8);
    Node *e=new Node(11);
    Node *f=NULL;
    Node *g=new Node(6);
    a->left=b;a->right=c;
    b->left=d;b->right=e;
    c->left=f;c->right=g;
    if (isCBT(a) && isMax(a)) cout<<"Tree is MaxHeap";
    else cout<<"Tree is not a MaxHeap";
}