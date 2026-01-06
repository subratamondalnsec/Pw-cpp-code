#include<bits/stdc++.h>
using namespace std;
class Bike{
public:
    static int noOfBicks;//this belong to the class
    int tyresize;
    int enginesize;
    //constructor
    Bike(int tyresize,int enginesize){//parameterized constructor
       this->tyresize=tyresize;//ar initial value 
       this->enginesize=enginesize;
    }
    static void increaseNoofBikes(){
        noOfBicks++;
    }
};
int Bike::noOfBicks=10;
// void print(){
//     static int x=10;
//     cout<<x<<endl;
//     x++;
// }
// void bin(){
//      int x=10;
//     cout<<x<<endl;
//     x++;
//}
int main(){
    // print();
    // print();
    // print();
    // bin();
    // bin();
    // bin();
    Bike tvs(12,100);
    Bike honda(14,150);
    Bike royal(15,200);
    royal.increaseNoofBikes();
    cout<<tvs.noOfBicks<<endl;
    cout<<honda.noOfBicks<<endl;
    tvs.increaseNoofBikes();
    cout<<royal.noOfBicks<<endl;
    cout<<tvs.tyresize<<"  "<<tvs.enginesize<<endl;
    cout<<honda.tyresize<<"  "<<honda.enginesize<<endl;
    cout<<royal.tyresize<<"  "<<royal.enginesize<<endl;
}
