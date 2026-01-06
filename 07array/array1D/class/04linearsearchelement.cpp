#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the array : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<=n-1;i++){
      cin>>arr[i];
}
int x;
cout<<"enter the element you want to seach :";
cin>>x;
bool flag= false;//check mark
for(int i=0;i<=n-1;i++){
    if(arr[i]==x) flag=true;
    // {
    // cout<<"present element";
    // break;
    // }
    // else{ 
    //     cout<<"not present element";
    //     break;
    //     }
}
    if(flag==true) cout<<"element found";
    else cout<<"element  not found";

}