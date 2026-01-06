#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    cout<<"enter elements of the array"<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x,count=0;
    cout<<"target";
    cin>>x;
    for(int i=0;i<n;i++){
        if(arr[i]>x) count++;
    }
    cout<<count;
}