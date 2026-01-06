#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        bool flag = true;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                flag=false;
            }
        }
        if(flag==true) break;
    }
}
int main() {
 int arr[5]={7,2,32,5,20};
 int size=5;
 int k=3;
 bubbleSort(arr,5);
 cout<<arr[k-1]<<endl;
 return 0;
}