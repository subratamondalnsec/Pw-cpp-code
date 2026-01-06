#include<iostream>
using namespace std;
void swap(int *x,int *y){
    int temp;
   temp=*x;
   *x=*y;
   *y=temp;
   return;
}
int main(){
    int i,n;
      cout<<"enter the 1st number : ";
    cin>>n;
   cout<<"enter the 1st number : ";
    cin>>i;
    swap(&n,&i);
    cout<<" its swap :"<<n<<" "<<i;
}