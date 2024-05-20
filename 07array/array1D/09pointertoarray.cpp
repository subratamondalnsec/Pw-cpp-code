#include<bits/stdc++.h>
using namespace std;
int main(){
        int arr[]={ 1,2,3,4,5,6};
        int* ptr=arr;
        for(int i=0;i<=5;i++){//print the value
            cout<<ptr[i]<<" ";//for(int i=0;i<=5;i++){
        }                     //cout<<*ptr;
        cout<<endl;           //ptr++;
        *ptr=8 ;// ptr[0]=8;//update the value
       ptr++;
       *ptr=9 ;
       ptr--;
        cout<<sizeof(ptr)<<endl;//can not access size
        for(int i=0;i<=5;i++){
            cout<<ptr[i]<<" ";//i[ptr],i[arr]
        }

    }
