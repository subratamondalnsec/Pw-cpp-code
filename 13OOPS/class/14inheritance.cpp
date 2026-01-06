#include<bits/stdc++.h>
using namespace std;
class vechicle{
public:
    int tyresize;
    int enginesize;
    int lights;
    string comanyName;

    vechicle(){
        cout<<"vechicle call hua "<<endl;
    }
};
class car: public vechicle{//car inherits vechicle
    public:
    int steeringsize;
};
class bike: public vechicle{//derived class,child class
    public:
    int handlesize;
    bike(){
        cout<<"bike call hua ";
    }
};
int main(){
    bike honda;
    honda.handlesize=5;
    honda.tyresize=10;
    honda.enginesize=500;
    cout<<honda.tyresize<<endl;
}