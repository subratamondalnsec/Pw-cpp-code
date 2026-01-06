#include <bits/stdc++.h>
using namespace std;
int main() {
    string str="12345678";
    char max = '!', smax = '!';
    for (int i=0;i<str.length();i++) {
        if (str[i]>max) {
            smax = max;
            max = str[i];
        } 
        else if (str[i]>smax && smax!=max) {
            smax=str[i];
        }
    }
    if(smax=='!') cout << "No second lagest string Number";
    cout << "lagest string Number : "<<max<<endl;
    cout << "second lagest string Number : "<<smax;
}
