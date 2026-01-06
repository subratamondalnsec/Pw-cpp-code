#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={7,1,2,5,8,4,9,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    int maxsum=INT_MIN;
    int maxidx=-1;
    int sum=0;
     for(int i=0;i<k;i++){//sliding method
        sum+=arr[i];//tno=k
     }
      maxsum=sum;
      int i=1;//sliding method
      int j=k;
      while(j<n){//tno=n-k
       sum+=arr[j]-arr[i-1];
        if(maxsum<sum){
            maxsum=sum;
            maxidx=i;
        }//TC=O(k+n-k)=O(n)
        i++;
        j++;
      }
    // for(int i=0;i<=n-k;i++){//tc-O(n*k)
    //     int sum=0;
    //     for(int j=i;j<i+k;j++){
    //         sum+=arr[j];
    //     }
    //   if (maxsum<sum){
    //     maxsum=sum;
    //     maxidx=i;
    //     }
    // }

    cout<<maxsum<<endl;
    cout<< maxidx;
}