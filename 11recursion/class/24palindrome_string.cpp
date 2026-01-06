/*#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(string s){
    int i=0;
    int j=s.length()-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int main(){
    string str ="nkjbnm";
   ispalindrome(str)? cout<<"it is palindrome" :cout<<"it not is palindrome";
}*/
/* recursion method*/
#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(string s,int i,int j){
    if(i>j) return true;
    if(s[i]!=s[j]) return false;
    else return ispalindrome(s,i+1,j-1);
    } 
int main(){
    string str ="nkjbnm";
   ispalindrome(str,0,str.length()-1)? cout<<"it is palindrome" :cout<<"it not is palindrome";
}