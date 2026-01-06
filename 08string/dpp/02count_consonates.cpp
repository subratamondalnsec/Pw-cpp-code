#include <bits/stdc++.h>
using namespace std;

int main() {
    int count = 0;
    string s = "subrata";
    // getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        //while(s[i]!='\0'){
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')  
            continue;
         else   count++; 
    }
        
    cout << count;
    return 0;
}