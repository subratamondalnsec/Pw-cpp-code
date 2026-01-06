#include<bits/stdc++.h>
using namespace std;
class Bike{
public:
    int tyresize;
    int enginesize;
    Bike(int ts,int e) :tyresize(ts),enginesize(e){//initalisationlist

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