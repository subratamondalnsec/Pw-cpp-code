#include<bits/stdc++.h>
using namespace std;
class Bike{
public:
    int tyresize;
    int enginesize;
    //constructor
    Bike(int tyresize,int enginesize){//parameterized constructor
       this->tyresize=tyresize;//ar initial value
       this->enginesize=enginesize;
        cout<<" call hua"<<endl;
    }
    ~Bike(){//destructor
        cout<<" mai khatam ho raha hu"<<endl;
    }
};
int main(){
    Bike tvs(12,100);
    Bike honda(14,150);
    Bike royal(15,200);
    cout<<tvs.tyresize<<"  "<<tvs.enginesize<<endl;
    cout<<honda.tyresize<<"  "<<honda.enginesize<<endl;
    cout<<royal.tyresize<<"  "<<royal.enginesize<<endl;
}