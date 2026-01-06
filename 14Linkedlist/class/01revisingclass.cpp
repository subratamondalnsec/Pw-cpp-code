#include <bits/stdc++.h>
using namespace std;
class Student{
public:
    string name;
    int rno;
    float marks;
    Student(string n,int r,float m){
    name=n;
    rno=r;
    marks=m;
    }
};
   void change(Student &s){
    s.name="raghav";
   }
   void changes(Student *s){
    s->name="sanket";
   }
int main(){
    Student *s= new Student("subrata mondal",6,92.7);
   cout<< s->name<<endl;
   // Student*ptr=&s;
   // (*ptr).name="raghav";
//    ptr->name="sanket";
    // change(s);
    // cout<< s.name<<endl;
    // changes(&s);
    // cout<< s.name<<endl;
}