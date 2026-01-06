/*#include <bits/stdc++.h>
using namespace std;//normal method
int hcf(int a,int b){//t.c=>O(min(a,b))
    for(int i=min(a,b);i>=2;i--){
        if(a%i==0 && b%i==0) return i;
    }
    return 1;
}
int main(){
    int a=45;
    int b=27;
    cout<<hcf(a,b);
}*/
/* recursion*/
#include <bits/stdc++.h>
using namespace std;
int gcf(int a,int b){//t.c=>O(log(a+b)) induction
    if(a==0) return b;
    else return gcf(b%a,a);
}
int main(){
    int a=45;
    int b=27;
    cout<<gcf(a,b);
}