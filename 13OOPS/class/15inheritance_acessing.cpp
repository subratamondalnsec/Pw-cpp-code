#include<bits/stdc++.h>
using namespace std;
class vechicle{
public:
    int tyresize;
protected:
    int enginesize;
private:
    int lights;
    string comanyName;

    vechicle(){
        cout<<"vechicle call hua "<<endl;
    }
};
class bike: public vechicle {//derived class,child class
    public:
    int handlesize;
};
int main(){

}