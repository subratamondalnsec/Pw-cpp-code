#include<bits/stdc++.h>
using namespace std;
class vehicle{
public:
    int a_ka_public;
   virtual void show(){
        cout<<"mai A hain "<<endl;
   }
};
class Bike: public vehicle {
    public:
    int b_ka_public;
     void show(){//its comment 
        cout<<"Aham B hain "<<endl;
    }
};
int main(){
    // vehicle a;
    // a.show();
    // Bike b;
    // b.show();
    // b.vehicle::show();
    Bike b;
    vehicle *a;
    a=&b;
    a->show();
}