#include<bits/stdc++.h>
using namespace std;
class Bike{
public:
    int tyresize;
    int enginesize;
    Bike(int ts,int e) :tyresize(ts),enginesize(e){}
    Bike(int ts) :tyresize(ts),enginesize(100){}
};
int main(){
    Bike tvs(15,200);
    Bike honda(16);
    cout<<tvs.tyresize<<"  "<<tvs.enginesize<<endl;
    cout<<honda.tyresize<<"  "<<honda.enginesize<<endl;
}