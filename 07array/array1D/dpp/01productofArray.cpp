#include <iostream>
using namespace std;
int main() {
    int arr[5]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int pdt = 1;
    for(int i=0;i<n;i++){
        pdt*=arr[i];
    }
    cout<<pdt;
    return 0;
}