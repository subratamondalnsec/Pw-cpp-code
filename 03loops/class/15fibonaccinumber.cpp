#include<bits/stdc++.h>
using namespace std;
// int main(){//nth fabonaci number
//     int n,temp=0,a=1,b=1;
//     cout<<"enter a n: ";
//     cin>>n;
//     for(int i=1;i<=n-2;i++){
//     temp=a+b;
//     a=b;
//     b=temp;
//     }
// cout<<b;
// }
//Calculate fibonaci Sum
// int CalculatefiboSum(int n){
//      if(n<=0){
//         return 0;
//     }
//    //0 1 1 2 3 5 8
//     //ARRAY DECLARATION
//     int fibo[n+1];
//     //INTIALIZATION
//     fibo[0]=0, fibo[1]=1;
//     //SUM DECLARATION
//     int sum=fibo[0]+fibo[1];
//     for(int i=2;i<=n;i++){
//         fibo[i]=fibo[i-1]+fibo[i-2];
//         sum+=fibo[i];
//     }
//     return sum;
// }

// int main(){
//     int q;
//     cin>>q;
//     while(q--){
//     int n;
//     cin>>n;
//     int sum=CalculatefiboSum(n);
//     cout<<sum;
//     }
// }