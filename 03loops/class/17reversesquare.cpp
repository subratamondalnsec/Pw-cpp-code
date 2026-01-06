#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int a=10;a<=100;a++){
    int b=0,x,y=0,z,temp;
    x=a*a;
    temp=x;
    z=a;
    while(z!=0){
        int i;
        i=z%10;
        y=y*10+i;
        z/=10;
    }
     while(temp!=0){
        int i;
        i=temp%10;
        b=b*10+i;
        temp/=10;
    }
    if((y*y)==b)cout<<"match number"<<a<<endl;

}
   
}