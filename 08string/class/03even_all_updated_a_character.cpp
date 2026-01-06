#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "subrata";
     cout<<s<<endl;
    for(int i=0;s[i]!='\0';i++){
        if(i%2==0) s[i]='a';
     }
     cout<<s<<endl;
}