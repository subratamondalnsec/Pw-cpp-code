#include <bits/stdc++.h>
using namespace std;
    string countAndSay(int n) {
        if(n==1) return "1";
        string str= countAndSay(n-1);
        string ztr="";
        int freq=1;
        char ch=str[0];
        for(int i=1;i<str.length();i++){
            char dh=str[i];
            if(ch==dh){
                freq++;
            }
            else{
                ztr=ztr+(to_string(freq)+ch);
                ch=dh;
                freq=1;
            }
        }
         ztr=ztr+(to_string(freq)+ch);
         return ztr;
    }
    int main() {
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    string result = countAndSay(n);
    cout << "The " << n << "-th term in the count-and-say sequence is: " << result << endl;

    return 0;
}