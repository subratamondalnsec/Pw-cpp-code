#include<bits/stdc++.h>
using namespace std;
class ddmmyyyy{//class
private:
   int date;
   int month;//data member
   int year;
public:
    ddmmyyyy(int d, int m,int y){
        date=d;
        month=m;
        year=y;
    }
   void setdate(int date){
    this->date=date;
   }
   void setmonth(int month){
    this->month=month;
   }
   void setyear(int year){
    this->year=year;
   }
   int getdate(){
    return date;
   }
   int getmonth(){
    return month;
   }
   int getyear(){
    return year;
   }
};
   string check(ddmmyyyy a,ddmmyyyy b){
    if(a.getdate()==b.getdate() && a.getmonth()==b.getmonth() && a.getyear()==b.getyear()) return "equal";
    else return "unequal";
   }
int main(){ 
    ddmmyyyy s(24,01,2005);
    ddmmyyyy l(24,05,2007);
    cout<<check(s,l);
}
