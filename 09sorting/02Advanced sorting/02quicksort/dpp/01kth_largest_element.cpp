#include <bits/stdc++.h>
using namespace std;
int partition(int arr[],int si,int ei){
    int pivotElement = arr[(si+ei)/2];
    int count=0;
    for(int i=si;i<=ei;i++){
        if(i==(si+ei)/2) continue;
        if(arr[i]<=pivotElement) count++;
    }
    int pivortIdx=count+si;
    swap(arr[(si+ei)/2],arr[pivortIdx]);
    int i=si;
    int j= ei;
    while(i<pivortIdx && j>pivortIdx){
        if(arr[i]<=pivotElement) i++;
        if(arr[j]>pivotElement) j--;
        else if(arr[i]>pivotElement && arr[j]<=pivotElement){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivortIdx;
}
int kthlargest(int arr[],int si,int ei,int k){
    int pi=partition(arr,si,ei);
    if((pi+1)==k) return arr[pi];
    else if((pi+1)<k) return  kthlargest(arr,pi+1,ei,k);
    else  kthlargest(arr,si,pi-1,k);
}
int main(){
    int arr[]={5,1,8,2,7,6,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "; 
    }
    cout<<endl;
    int k=0; 
    cout<< kthlargest(arr,0,n-1,n-k);    
}