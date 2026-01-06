/*#include <bits/stdc++.h>
using namespace std;
void binarystring(string s,int n){//with consective 1s
if(n==s.length()) {
    cout<<s<<endl;
    return;
}
binarystring(s+'0',n);
binarystring(s+'1',n);
}
int main(){
    int n=3;
    binarystring("",n);
}*/
#include <bits/stdc++.h>
using namespace std;
void binarystring(string s,int n){//without consective 1s
if(n==s.length()) {
    cout<<s<<endl;
    return;
}
binarystring(s+'0',n);
if((s=="")|| (s[s.length()-1]=='0')){ 
binarystring(s+'1',n);
}
}
int main(){
    int n=4;
    binarystring("",n);
}