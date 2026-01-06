#include<bits/stdc++.h>
using namespace std;
class vehicle{
public:
    int topspeed;
   virtual void sound(){
        cout<<" vehical vroom vroom "<<endl;
   }
};
class Bike: public vehicle {
    public:
    int gears;
     void sound(){//its comment 
        cout<<"Bike Dhoom Dhoom "<<endl;
    }
};
int main(){
    vehicle* v=new Bike;
    v->sound();
}