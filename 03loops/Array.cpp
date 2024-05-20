//largest----> 1 2 3 4 5 
//second largest ----> 1 2 3 6 2
//largest and second largest dono print hoo


#include<bits/stdc++.h>
using namespace std;
int LargestNumber(int arr[],int n){
    int largest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
          largest=arr[i];
        }
    }
    return largest;

}

int main(){
    int arr[]={2,5,9,4,98};
    cout<<LargestNumber(arr,5)<<endl;
}