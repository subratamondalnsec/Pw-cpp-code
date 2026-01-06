#include<iostream>
using namespace std;
int main()
{
 int amount;
 int n1,n2,n5,n10,n20,n50,n100,n200,n500;
/* Note : here you can take another variable for a 2000 rupees note, and modify the 
code accordingly.
*/ 
 n1 = n2 = n5 = n10 = n20 = n50 = n100 =n200 = n500 =0;
 cout<<"Please Enter Your total Amount to find the notes : ";
 cin>>amount;
 switch(amount>=500)
 {
 case 1:
 n500 = amount/500;
 amount -= n500 * 500;
 break;
 }
  switch(amount>=200)
 {
 case 1:
 n200 = amount/200;
 amount -= n200 * 200;
 break;
 }
 switch(amount >=100)
 {
 case 1:
 n100 = amount/100;
 amount -= n100 * 100;
 break;
 }
 switch(amount >=50)
 {
 case 1:
 n50 = amount/50;
 amount -= n50 * 50;
 }
 switch(amount >=20)
 {
 case 1:
 n20 = amount/20;
 amount -= n20 * 20;
 break;
 }
 switch(amount >=10)
 {
 case 1:
 n10 = amount/10;
 amount -= n10 * 10;
 break;
 }
switch(amount >=5)
 {
 case 1:
 n5= amount/5;
 amount -= n5* 5;
 break;
 }
switch(amount >=2)
 {
 case 1:
 n2= amount/2;
 amount -= n2* 2;
 break;
 }
  switch(amount >=1)
 {
 case 1:
 n1 = amount;
 amount -= n1;
 break;
 }


cout<<"500 note :"<<n500<<endl;
cout<<"200 note :"<<n200<<endl;
cout<<"100 note :"<<n100<<endl;
cout<<"50 note :"<<n50<<endl;
cout<<"20 note :"<<n20<<endl;
cout<<"10 note :"<<n10<<endl;
cout<<"5 note :"<<n5<<endl;
cout<<"2 note :"<<n2<<endl;
cout<<"1 note :"<<n1<<endl;

}