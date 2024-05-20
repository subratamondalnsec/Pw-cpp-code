#include<bits/stdc++.h>
#include<vector>
using namespace std;
void display(vector<int>&a){
    for(int i=0;i<a.size();i++){
            cout<<a[i]<<" "; 
        }
        cout<<endl;
}
void nextpermutation(vector<int>& nums){
    int idx=-1;
    int n=nums.size();
    for(int i=n-2;i>=0;i--){
        if(nums[i+1]>nums[i]){
            idx=i;
            break;
        }
    }
    if(idx==-1){//if array is already greatest
        reverse(nums.begin(),nums.end());
        return;
    }
    //sorting/reverse after pivot
     reverse(nums.begin()+idx+1,nums.end());
     //finding the just greatest element than idx
     int j=-1;
     for(int i=idx+1;i<n;i++)
     {
         if(nums[i]>nums[idx]){
            j=i;
            break;
        }
     }
     //swapping idx and j
    int temp= nums[idx];
    nums[idx] =nums[j];
    nums[j]=temp;
    return;
}
int main(){
 vector<int>v;
 int x,n;
 cin>>n;
for(int i=0;i<n;i++){
    cin>>x;
    v.push_back(x);
}
 display(v);
   nextpermutation(v);
   display(v);
  }