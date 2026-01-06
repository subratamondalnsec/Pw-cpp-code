#include<bits/stdc++.h>
using namespace std;
class vechicle{
public:
    int tyresize;
    friend void show(vechicle &v);
protected:
    int enginesize;
private:
    int lights=11;   
};
 void show(vechicle &v){
        cout<< v.lights <<endl;
    }
int main(){
   vechicle v;
   show(v);

}