#include<bits/stdc++.h>
using namespace std;
void display(int a[],int size){//paasing by referance
     for(int i=0;i<=size-1;i++){
        cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
void change(int b[],int size){//update the value
    b[0]=100;
    return; 
}

int main(){
    int arr[]={ 1,2,3,4,5,6};
    int size =sizeof(arr)/sizeof(arr[0]);
    display(arr,size);
    change(arr,size);
    display(arr,size);
}