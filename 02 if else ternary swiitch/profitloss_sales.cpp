#include<bits/stdc++.h>
using namespace std;
int main(){
     int cp,sp;
     cout<<"enter the cost price :";
     cin>>cp;
     cout<<"enter the sale price :";
     cin>>sp;
     if(sp>cp){
        cout<<"its profit: "<<(sp-cp);
     }else if(sp<cp){
        cout<<"its loss: "<<-(sp-cp);
        }else
         cout<<" its no profit and no loss 0";

}