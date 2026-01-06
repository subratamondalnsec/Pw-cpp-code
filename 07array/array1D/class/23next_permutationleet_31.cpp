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
        if(nums[i+1]>nums[i]){//4>2
            idx=i;//1
            break;
        }
    }
    if(idx==-1){//if array is already greatest
        reverse(nums.begin(),nums.end());
        return;
    }
    //sorting/reverse after pivot
     reverse(nums.begin()+idx+1,nums.end());//1234
     //finding the just greatest element than idx
     int j=-1;
     for(int i=idx+1;i<n;i++)
     {
        if(nums[i]>nums[idx]){//3>2
            j=i;//2
            break;
        }
     }
    //swapping idx and j
    int temp= nums[idx];//2
    nums[idx] =nums[j];//3
    nums[j]=temp;//1324
    return;
}
int main(){
 vector<int> v = {1,2, 4, 3};
    cout << "Original array: ";
    display(v);
   nextpermutation(v);
    cout << "Next permutation: ";
   display(v);
  }