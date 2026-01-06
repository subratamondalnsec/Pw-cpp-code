#include<bits/stdc++.h>
using namespace std;
class Book{//class
public:
   string name;
   int price;
   int NoOfPages;//data member
   int countBooks(int p){
    if(price<p) return 1;
    else return 0;
   }
   int isBookpresent(string book){
    if(name==book) return true;
    else return false;
   }
};
int main(){
       Book harrypotter;
       harrypotter.name="Harry Potter";
       harrypotter.price=1000;
       harrypotter.NoOfPages=500;
       cout<<harrypotter.countBooks(2000)<<endl;
       cout<<harrypotter.isBookpresent("Harry Potter");
    }