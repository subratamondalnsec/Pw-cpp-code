#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the number :";
    cin>>n;
      if((n%5==0||n%3==0)&&n%15==0)
      cout<<"the number is divisible 5 and 3 not 15";
      else
        cout<<"the number is not divisible 5 and 3 not 15";
}