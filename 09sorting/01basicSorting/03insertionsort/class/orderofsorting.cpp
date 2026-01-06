#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={15,4,26,3,12,21};
    int n =sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     }
     vector<int>v(n,0);//it all case
     int x=0;
     for(int i=0;i<n;i++){
        int mindx=-1;
        int min=INT_MAX;
         for(int j=0;j<n;j++){
            if(v[j]==1)continue;
            else{
                if(min>arr[j]){
                    min=arr[j];
                    mindx=j;
                }
            }
        }
        arr[mindx]=x;
        v[mindx]=1;
        x++;
     }

    ////only +ve number
    //  int x=0;
    //  for(int i=0;i<n;i++){
    //     int mindx=-1;
    //     int min=INT_MAX;
    //      for(int j=0;j<n;j++){
    //         if(arr[j]<=0)continue;
    //         else{
    //             if(min>arr[j]){
    //                 min=arr[j];
    //                 mindx=j;
    //             }
    //         }
    //     }
    //     arr[mindx]=-x;
    //     x++;
    //  }
     cout<<endl;
        for(int i=0;i<n;i++){
           // arr[i]=-arr[i];
        cout<<arr[i]<<" ";
     }
    }