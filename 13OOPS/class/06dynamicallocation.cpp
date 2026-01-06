#include<bits/stdc++.h>
using namespace std;
class player{//class
private:
   int score; 
   int age;
   bool alive;
   int health;//data member
public: 
    void setscore(int score){//setter
       this->score= score;
    }
    void sethealth(int health){//setter
        this->health=health;
    }
    void setage(int a){//setter
        this->age=age;
    }
    void setalive(int alive){//setter
        this->alive=alive;
    }
   int getscore(){
    return score;
   }
   int gethealth(){
    return health;
   }
   int getage(){
    return age;
   }
   int getalive(){
    return alive;
   }
};
int main(){
    player harsh;//odject creation ,statically//compile time,static allocation.
    player *urvi=new player;//run time,dynamic allocation
    player urviobject=*urvi;
    player *subrata=new player;
    player *raghav=new player;
    harsh.setscore(80);
    harsh.sethealth(20);
    harsh.setage(20);
    harsh.setalive(true);
    urviobject.setscore(70);
    urviobject.sethealth(80);
    urviobject.setage(50);
    urviobject.setalive(true);
    (*subrata).setscore(200);
    (*subrata).sethealth(900);
    (*subrata).setage(19);
    (*subrata).setalive(true);
    raghav->setscore(90);//arrow operator
    raghav->sethealth(70);
    raghav->setage(30);
    raghav->setalive(true);
   cout<<urviobject.getscore()<<endl;
   cout<<(*subrata).getscore()<<endl;
    cout<<raghav->getscore()<<endl;
}