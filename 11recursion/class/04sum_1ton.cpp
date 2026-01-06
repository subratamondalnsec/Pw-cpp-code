#include <bits/stdc++.h>
using namespace std;
// void sumextraparameter(int n,int sum){//bakar method
//     if(n==0){
//         cout<< sum<<endl;//kaam
//          return;
//          }//base case
//      sumextraparameter(n-1,sum+n);  //call  
// }
int sum(int n){
    if(n==0) return 0;
 return  n+sum(n-1);
}
int main(){
    int n;
    cout<<"enter the number :";
    cin>> n;
   // sumextraparameter(n,0);
    cout<<endl<< sum(n);
   
}