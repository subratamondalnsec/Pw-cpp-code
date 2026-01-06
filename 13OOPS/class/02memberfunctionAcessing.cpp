#include<bits/stdc++.h>
using namespace std;
class player{//class
public:
   int score;
   int health;//data member
   void showHeaith(){//member function
    cout<<"health is :"<<health<<endl;
   }
    void showscore(){
    cout<<"score is :"<<score<<endl;
   }
};
int main(){
        player amit;//object
        amit.score=90;
        amit.health=100;
        player harsh;
        harsh.score=100;
        harsh.health=20;
        amit.showHeaith();
        amit.showscore();
        harsh.showHeaith();
        harsh.showscore();
    }