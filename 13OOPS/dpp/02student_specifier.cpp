#include<bits/stdc++.h>
using namespace std;
class Student{
private:
    int roll_number;
    string Name;
    string Department;
    string Course; 
    int Year_of_joining;
public:
    Student(int r,string n,string d,string c,int y){
    roll_number=r;
    Name=n;
    Department=d;
    Course=c; 
    Year_of_joining=y;       
    }
    int getRollNumber(){
        return roll_number;
    }
    string getName(){
        return Name;
    }
    string getDepartment() const {
        return Department;
    }
    string getCourse() const {
        return Course; 
    }
    int getYearOfJoining() const {
        return Year_of_joining;
    }
};
bool sameDepartment(Student a,Student b){
    if(a.getDepartment()==b.getDepartment()) return true;
    else return false;
}
int main(){
    Student subrata(162,"subrata","cse","B.Tech",2023);
    Student susovan(170,"susovan","cse","B.Tech",2023);
    if (sameDepartment(susovan,subrata)==true) {
        cout << "Both students are in the same department.\n";
   } 
   else {
        cout << "Students are in different departments.\n";
    }
}