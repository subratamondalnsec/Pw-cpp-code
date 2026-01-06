#include<bits/stdc++.h>
using namespace std;
class vechicle{
public:
    int tyresize;

   virtual void caculation()=0;
   virtual void refuel()=0;
};
class bike: public vechicle{
    public:
    int handlesize;
    void caculation(){
        cout<<"calculate";
    }
    void refuel(){
        cout<<"refuel";
    }
};
int main(){
    bike honda;
    honda.handlesize=5;
    honda.tyresize=10;
}