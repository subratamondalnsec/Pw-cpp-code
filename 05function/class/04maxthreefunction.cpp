 #include<bits/stdc++.h>
using namespace std;
   int maxthree(int x,int y,int z){
   if(x>y&&x>z){
       return x;
     }else if(y>z){
         return y;
    }else
    return z;
}
int main(){
    int a,b,c;
    cout<<"enter the 1st number:";
    cin>>a;
     cout<<"enter the 2nd number:";
    cin>>b;
      cout<<"enter the 3rd number:";
    cin>>c;
    cout<<"it maximum :"<<maxthree(a,b,c);
}