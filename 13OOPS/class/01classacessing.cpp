#include<bits/stdc++.h>
using namespace std;
class player{//class
public:
   int score;
   int health;//data member
};
int main(){
        player amit;//object
        amit.score=90;
        amit.health=100;
        cout<<amit.score<<endl;
        cout<<amit.health<<endl;
        player harsh;
        harsh.score=100;
        harsh.health=20;
        cout<<harsh.score<<endl;
        cout<<harsh.health;
    }