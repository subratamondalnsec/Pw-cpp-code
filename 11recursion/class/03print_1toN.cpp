#include <bits/stdc++.h>
using namespace std;
void print(int n){
    if(n==0) return;//base case
     print(n-1);  //call
    cout<< n<<endl;//kaam
}
void  printextraparameter(int i,int n){// print extra parameter
    if(i>n) return;
    cout<<i<<endl;
    printextraparameter(i+1,n);
}

int main(){
    int n;
    cout<<"enter the number :";
    cin>> n;
    print(n);
    cout<<endl;
     printextraparameter(1,n);
}