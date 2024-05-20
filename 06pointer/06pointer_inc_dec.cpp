#include<bits/stdc++.h>
using namespace std;
int main(){
     int x=4;
     int*ptr =&x;
     cout<<*ptr<<endl;//4
     cout<<ptr<<endl;//address of ptr
    //  ptr++;
    //  cout<<*ptr<<endl;//address of ptr+4 byte
    //  cout<<ptr<<endl;//garbage value
     *ptr=*ptr+1;
      ++(*ptr);
     cout<<*ptr<<endl;
     cout<<ptr<<endl;
     } 