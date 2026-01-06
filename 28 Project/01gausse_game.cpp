/*
You are tasked with Implementing a simple number guessing game in C++ involving a Guesser, 
three Players, and an Umpire. The game operates as follows:

Guesser: This entity will guess a number.

Players: Each of the three players will guess a number. 3 players p1-2 p2->4 p3->2

Umpire: This entity will collect the guesses from the Guesser and the Players and determine which Players, if any, have guessed the same number as the Guesser.

p1->2 p2->4 p3->2

x -> 4

p1 lost the game

p2 won the game
*/

#include<bits/stdc++.h>
using namespace std;
class Guesser{
    int guessdnum;
    public:
    int takeguesserinput(){
        int x;
        cout<<"Give the number for the guesser : ";
        cin>>x;
        guessdnum=x;
        return guessdnum;
    }
};
class player{
    int playernum;
    public:
    int takeplayerinput(){
        int p;
        cin>>p;
        playernum=p;
        return playernum;
    }
};

class umpire{
public:
    int g;
    int p1,p2,p3;
    void GetTheNumberFromGuesser(){
        Guesser g1;
        g=g1.takeguesserinput();
    }
    void GetTheNumberFromplayer(){
        player plr1,plr2,plr3;
        cout<<"\n Give the number for the guessed by player 1 : ";
        p1=plr1.takeplayerinput();
        cout<<"\n Give the number for the guessed by player 2 : ";
        p2=plr2.takeplayerinput();
        cout<<"\n Give the number for the guessed by player 3 : ";
        p3=plr3.takeplayerinput();
    }
    void printTheResult(){
        // g  p1 p2 p3
        if(g==p1){
            if(g==p2){
                if(g==p3) cout<<"All the player has won the game"<<endl;
                else cout<<"The player 1 and 2 has won the game"<<endl;
            }
           else if(g==p3) cout<<"The player 1 and 3 has won the game"<<endl;
           else cout<<"The player 2 has won the game"<<endl;
        }
        else if(g==p2){
           if(g==p3) cout<<"The player 2 and 3 has won the game"<<endl;
           else cout<<"The player 2 has won the game"<<endl;
        }
        else if(g==p3){
            cout<<"The player 3 has won the game"<<endl;
        }
        else{
            cout<<"All the player has loss the game";
        }

    }
};


int main(){
    cout<<"----- Let's start the Game -----\n";
    umpire u;
    u.GetTheNumberFromGuesser();
    u.GetTheNumberFromplayer();
    u.printTheResult();


    cout<<"----- End Game -----\n";
}