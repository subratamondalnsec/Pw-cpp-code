#include<bits/stdc++.h>
using namespace std;
int main(){
   char n;
    cout<<"enter the character :";
    cin>>n;
    if((n>=65&&n<=90)||(n>=97&&n<=122)){
        if(n=='a'||n=='e'||n=='i'||n=='o'||n=='u'){
    cout<<"its alphabet and vowel";
    }
    else
     cout<<"its alphabet and consonant";
    }
    else
    cout<<"its not a alphabet";
}    