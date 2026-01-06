#include<bits/stdc++.h>
using namespace std;
vector<int>st;

void buildSegmentTree(int arr[],int i,int lo,int hi){
    if(lo==hi){
        st[i]=arr[lo];
        return;
    } 
    int mid=lo+(hi-lo)/2;
    buildSegmentTree(arr,2*i+1,lo,mid);//left subtree
    buildSegmentTree(arr,2*i+2,mid+1,hi);//right subtree
    st[i]=max(st[2*i+1],st[2*i+2]); 
}
int getmax(int i,int lo,int hi,int& l,int& r){
    if(l>hi || r<lo) return INT_MIN;
    if(lo>=l && hi<=r) return st[i];
    int mid=lo+(hi-lo)/2;
    int leftMax=getmax(2*i+1,lo,mid,l,r);
    int rightMax=getmax(2*i+2,mid+1,hi,l,r);
    return max(leftMax,rightMax);
}
int main(){
    int arr[]={1,4,2,8,6,4,9,3};//0 to 7
    int n=sizeof(arr)/4;
    st.resize(4*n);
    buildSegmentTree(arr,0,0,n-1);

    int q,l,r; cin>>q;
    while(q--){
        cout<<"\nEnter the range : ";
        cin>>l>>r;
        cout<<endl<<getmax(0,0,n-1,l,r);
    }

}