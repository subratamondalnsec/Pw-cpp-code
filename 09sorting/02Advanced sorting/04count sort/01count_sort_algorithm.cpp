#include <bits/stdc++.h>
using namespace std;
void countSort(vector<int>&v){
    int n=v.size();
    int max_ele=INT_MIN;
    for(int i=0;i<n;i++) max_ele=max(v[i],max_ele);
    vector<int>freq(max_ele+1,0);
    for(int i=0;i<n;i++)  freq[v[i]]++;
    for(int i=1;i<=max_ele;i++)  freq[i]+=freq[i-1];
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--)  ans[--freq[v[i]]]=v[i];
    for(int i=0;i<n;i++)  v[i]=ans[i];
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i =0;i<n;i++) cin>>arr[i];
    countSort(arr);
    for(int i =0;i<n;i++) cout<<arr[i]<<" ";
}