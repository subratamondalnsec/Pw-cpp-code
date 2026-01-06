// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//    int n;
//     cout<<"Numder of colums of *:";
//         cin>>n;
//         for(int i=1;i<=n-1;i++) cout<<" ";
//         cout<<"*";
//         cout<<endl;
//         for(int i=2;i<=n-1;i++){
//              for(int j=1;j<=n-i;j++){
//                 cout<<" ";
//             }
//             cout<<"*";
//             for(int j=1;j<=2*(i-1)-1;j++){
//                 cout<<" ";
//             }
//             cout<<"*";
//             cout<<endl;
//         }         
//     for(int i=1;i<=n;i++){
//         for(int j=2;j<=i;j++){
//             cout<<" "; 
//         }
//         //for(int k=i;k<=i;k++){
//             cout<<"*";
//         //}
//         for(int j=1;j<=2*(n-i)-1;j++){
//             cout<<" "; 
//         }
//        // for(int k=i;k<=i;k++){
//             if(i==n) continue;
//             cout<<"*";
//         //}
//         cout<<endl;
//     }
// }


#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
    cout<<"Numder of colums of *:";
        cin>>n;
         int  m=2*n-1;
        for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if( (i+j)==m/2 or abs(i-j)==m/2 or (i+j)==3*(n-1)) cout<<"*"; 
            else cout<<" ";
            }
            cout<<endl;
        }
}