#include<iostream>
using namespace std;
// unsigned long long factorial(long long n){//using recursion
//     unsigned long long result=1;
//     for(int i=1;i<=n;i++){
//         result*=i;
//     }
//     return result;
// }
// int main(){
//     long long n;
//     cin>>n;
//     cout<<factorial(n)<<endl;
// }
int main(){
    int i,n;
  unsigned long long int p=1;
      cout<<"enter the n : ";
    cin>>n;
    for(i=2;i<=n;i++){
        p*=i;
    }
    cout<<n<<" its factorial is :"<<p;
}