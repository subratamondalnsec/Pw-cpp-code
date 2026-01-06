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
int addscore(player a,player b){
    return a.getscore()+b.getscore();
}
player getmaxscore(player a,player b){
    if(a.getscore()>b.getscore()) return a;
    else return b;
}
int main(){
    player harsh;//odject creation ,statically
    player raghav;
    harsh.setscore(80);
    harsh.sethealth(20);
    harsh.setage(20);
    harsh.setalive(true);
    raghav.setscore(90);
    raghav.sethealth(30);
    raghav.setage(25);
    raghav.setalive(true);
    cout<<addscore(harsh,raghav)<<endl;
    player sanket =getmaxscore(harsh,raghav);
    cout<<sanket.getscore()<<endl;
    cout<<sanket.gethealth()<<endl;
}