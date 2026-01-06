#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={5,2,10};
    int n =sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     }
          cout<<endl;
    double kmin=float(INT_MIN);
    double kmax=float(INT_MAX);
    bool flag=true;
    for(int i=0;i<n-1;i++){
        if(arr[i]>=arr[i+1]) kmin=max(kmin,(arr[i]+arr[i+1])/2.0);
        else  kmax=min(kmax,(arr[i]+arr[i+1])/2.0);
        if(kmin>kmax){
            flag=false;
            break;
        }
    }
    if(flag==false) cout<<-1;
    else if(kmin==kmax){
        if(kmin-(int)kmin==0) cout<<"there are one of k : "<<kmin;
        else cout<<-1;
    }
        else{
            if(kmin-(int)kmin>0){
                kmin=(int)kmin+1;
            }
            cout<<"Range of k is :["<<kmin<<","<<(int)kmax<<"]";
        }

     }