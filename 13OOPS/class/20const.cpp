#include<bits/stdc++.h>
using namespace std;
class student{
    public:
       const int rollnumber;
       int age;
       student(int r,int a) : rollnumber(r),age(a){
    }
};
int main(){
    student s1(100,23);
    cout<<s1.rollnumber<<" "<<s1.age;
}