#include<bits/stdc++.h>
using namespace std;
class Gun{
public:
    int ammo;
    int damage;
    int scope;
};
class player{//class
private:
  class Helmet{
    int hp;
    int level;
public:
    void setHp(int hp){
        this->hp=hp;
    }
    void setLevel(int level){
        this->level=level;
    }
    int getHp(){
        return hp;
    }
    int getLevel(){
        return level;
    }
   };
   int score;
   int age;
   bool alive;
   int health;//data member
   Gun gun;
   Helmet helmet;
  
public: 
    void setscore(int score){//setter
       this->score= score;
    }
    void sethealth(int health){//setter
        this->health=health;
    }
    void setage(int age){//setter
        this->age = age;
    }
    void setalive(int alive){//setter
        this->alive=alive;
    }
    void setGun(Gun gun){//setter
        this->gun=gun;
    }
    void setHelmet(int level){
        Helmet *helmet= new Helmet;
        helmet->setLevel(level);
        int health=0;
        if(level==1) health=25;
        else if(level==2) health=50;
        else if(level==3) health=100;
        else cout<<"error, invalid level!!";
        helmet->setHp(health);
        this->helmet= *helmet;
    }
    void getHelmet(){
       cout<<helmet.getHp()<<endl;
       cout<<helmet.getLevel()<<endl;
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
   Gun getGun(){
    return gun;
   }
};
int main(){
    player harsh;
    player raghav;
    player subrata;

    Gun akm;
    akm.ammo=100;
    akm.damage=50;
    akm.scope=2;

    harsh.setscore(80);
    harsh.sethealth(20);
    harsh.setage(20);
    harsh.setalive(true);
    harsh.setGun(akm);
    harsh.setHelmet(2);

    Gun awm;
    awm.ammo=15;
    awm.damage=150;
    awm.scope=8;

    raghav.setscore(90);
    raghav.sethealth(70);
    raghav.setage(30);
    raghav.setalive(true);
    raghav.setGun(awm);
    raghav.setHelmet(3);

   player players[3]={harsh,raghav,subrata};//Array Of object
   cout<<players[0].getscore()<<endl;
    cout<<players[1].getage()<<endl;
}