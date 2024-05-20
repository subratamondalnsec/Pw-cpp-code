#include<iostream>
using namespace std;
void swap(int x,int y){
    int temp;
   temp=x;
   x=y;
   y=temp;
   return;
}
int main(){
    int a,b;
      cout<<"enter the 1st number : ";
    cin>>a;
   cout<<"enter the 1st number : ";
    cin>>b;
    swap(a,b);
    cout<<" its swap :"<<a<<" "<<b;
}