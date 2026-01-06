#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void display(vector<int>arr){
    for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
    cout<<endl;
}
void inorder(Node* root,vector<int>&arr){
    if(root==NULL) return;
    inorder(root->right,arr);
    arr.push_back(root->val);
    inorder(root->left,arr);
}
void preorder(Node* root,vector<int>&arr,int &i){
    if(root==NULL) return;
    root->val=arr[i++];
    preorder(root->left,arr,i);
    preorder(root->right,arr,i);
}
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
int main(){
    Node *a=new Node(10);
    Node *b=new Node(5);
    Node *c=new Node(16);
    Node *d=new Node(1);
    Node *e=new Node(8);
    Node *f=new Node(12);
    Node *g=new Node(20);
    a->left=b;a->right=c;
    b->left=d;b->right=e;
    c->left=f;c->right=g;
    vector<int>arr;
    inorder(a,arr);
    display(arr);
    int i=0;
    preorder(a,arr,i);
    levelorder(a);
}