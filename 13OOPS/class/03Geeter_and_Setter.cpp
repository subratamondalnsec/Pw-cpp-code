#include<bits/stdc++.h>
using namespace std;
class player{//class
private:
   int score;
   int health;//data member
public: 
    void setscore(int s){//setter
        cout<<"score set kiya ja raha hai"<<endl;
        score=s;
    }
    void sethealth(int h){//setter
        cout<<"health change kiya ja raha hai"<<endl;
        health=h;
    }
   int getscore(){
    return score;
   }
   int gethealth(){
    return health;
   }
};
int main(){
        player amit;//object
        amit.setscore(60);
        amit.sethealth(40);
        cout<<amit.getscore()<<endl;
        cout<<amit.gethealth()<<endl;
        player harsh;
        harsh.setscore(80);
        harsh.sethealth(20);
       cout<<harsh.getscore()<<endl;
       cout<<harsh.gethealth()<<endl;
    }