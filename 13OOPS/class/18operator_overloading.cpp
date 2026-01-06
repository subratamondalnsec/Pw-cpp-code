#include<bits/stdc++.h>
using namespace std;
class complexNumber{
    public:
    int imaginary;
    int real;

  complexNumber add(complexNumber &c1){
    complexNumber c3;
    c3.imaginary=c1.imaginary+this->imaginary;
    c3.real=c1.real+this->real;
    return c3;
}  
  complexNumber operator +(complexNumber &c1){
    complexNumber c3;
    c3.imaginary=c1.imaginary+this->imaginary;
    c3.real=c1.real+this->real;
    return c3;
}
  complexNumber operator -(complexNumber &c1){
    complexNumber c3;
    c3.imaginary=c1.imaginary-this->imaginary;
    c3.real=c1.real-this->real;
    return c3;
}
};

int main(){
    complexNumber a1,a2;
    a1.imaginary=10;
    a1.real=5;
    a2.imaginary=12;
    a2.real=4;
    complexNumber a3;
    a3=a1.add(a2);
    cout<<"real :"<<a3.real<<" "<<"imaginary"<<a3.imaginary<<endl;
    a3=a1 + a2;
    cout<<"real :"<<a3.real<<" "<<"imaginary"<<a3.imaginary<<endl;
    a3=a1 - a2;
    cout<<"real :"<<a3.real<<" "<<"imaginary"<<a3.imaginary<<endl;

}