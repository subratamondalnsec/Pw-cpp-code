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
Node* construct(int arr[],int n){
    queue<Node*> q;
    Node *root=new Node(arr[0]);
    q.push(root);
    int i=1;
    int j= 2;
    while(q.size()>0&& i<n){
        Node *temp= q.front();
        q.pop();
        Node* l;
        Node* r;
        if(arr[i]!=INT_MIN) l=new Node(arr[i]);
        else l=NULL;
        if(j!=n && arr[j]!=INT_MIN) r=new Node(arr[j]);
        else r=NULL;
        temp->left=l;
        temp->right=r;
        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);
        i+=2;
        j+=2;
    }
    return root;
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
void Bottomview(Node* root){
    unordered_map<int,int>m;
    queue<pair<Node*,int> >q;
    q.push({root,0});
    while(q.size()>0){
        Node* temp=(q.front()).first;
        int level=(q.front()).second;
        q.pop();
        m[level]=temp->val;
        if(temp->left!=NULL)  q.push({temp->left,level-1});
        if(temp->right!=NULL)  q.push({temp->right,level+1});
    }
    int maxlevel=INT_MIN,minlevel=INT_MAX;
    for(auto x : m){
        maxlevel=max(maxlevel,x.first);
        minlevel=min(minlevel,x.first);
    }
    for(int i=minlevel;i<=maxlevel;i++) cout<<m[i]<<" ";
}
// Helper function to insert nodes in the binary tree for demonstration.
int main() {
    // Example usage:
    // int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN,7,8};
    int arr[] = {1, 2, 4,6,7, 5, 3};
    int n= sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr, n);

    // Print the result.
    levelorder(root);
    cout<<"Bottom view is :";
    Bottomview(root);
    return 0;
}