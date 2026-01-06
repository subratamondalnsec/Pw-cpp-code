#include<bits/stdc++.h>
using namespace std;
class cricketer{
public:
    string name;
    int age;
    int noOfTestMatches;
    int averagescore;
};
int main(){
    cricketer virat;
    virat.name="virat kholi";
    virat.age= 35;
    virat.noOfTestMatches=80;
    virat.averagescore=90;

    cricketer dhoni;
    dhoni.name="MS Dhoni";
    dhoni.age= 41;
    dhoni.noOfTestMatches=120;
    dhoni.averagescore=110;

    cricketer cricketers[2]={virat,dhoni};
    for(int i=0;i<2;i++){
    cout<<cricketers[i].name<<endl;
    cout<<cricketers[i].age<<endl;
    cout<<cricketers[i].noOfTestMatches<<endl;
    cout<<cricketers[i].averagescore<<endl;
    }
}