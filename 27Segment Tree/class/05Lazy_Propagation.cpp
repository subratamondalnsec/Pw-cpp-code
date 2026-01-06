/* By subrata mondal */
#include<bits/stdc++.h>
using namespace std;

vector<int>seg;
vector<int>lazy;
void build_segment_Tree(vector<int>& nums,int i,int lo,int hi){
    if(lo==hi){
        seg[i]=nums[hi];
        return;
    }
    int mid=lo+(hi-lo)/2;
    build_segment_Tree(nums,2*i+1,lo,mid);
    build_segment_Tree(nums,2*i+2,mid+1,hi);
    seg[i]=seg[2*i+1]+seg[2*i+2];
}
int getsum(int i,int lo,int hi,int& l,int& r){
    if(lazy[i]!=0){
        int rangesize=hi-lo+1;
        seg[i]+=(rangesize * lazy[i]);
        if(lo!=hi){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(l>hi || r<lo) return 0;
    if(lo>=l && hi<=r) return seg[i];
    int mid=lo+(hi-lo)/2;
    int leftsum=getsum(2*i+1,lo,mid,l,r);
    int rightsum=getsum(2*i+2,mid+1,hi,l,r);
    return leftsum+rightsum;
}

void updateRange(int i,int lo,int hi,int l,int r,int value){
    if(lazy[i]!=0){
        int rangesize=hi-lo+1;
        seg[i]+=(rangesize * lazy[i]);
        if(lo!=hi){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(l>hi || r<lo) return ;
    if(lo>=l && hi<=r){
        int rangesize=hi-lo+1;
        seg[i]+=(rangesize * value);
        if(lo!=hi){
            lazy[2*i+1]+=value;
            lazy[2*i+2]+=value;
        }
        return;
    }
    int mid=lo+(hi-lo)/2;
    updateRange(2*i+1,lo,mid,l,r,value);
    updateRange(2*i+2,mid+1,hi,l,r,value);
    seg[i]=seg[2*i+1]+seg[2*i+2];
}

int main(){
    vector<int>arr={1,4,2,8,6,4,9,3};//0 to 7
    int n=arr.size();
    seg.resize(4*n);
    lazy.resize(4*n,0);
    build_segment_Tree(arr,0,0,n-1);

    int q,l,r;
    cout<<"\nEnter the range : ";
    cin>>l>>r;
    cout<<endl<<getsum(0,0,n-1,l,r);
    updateRange(0,0,n-1,2,5,10);
    cout<<endl<<getsum(0,0,n-1,l,r);
}



