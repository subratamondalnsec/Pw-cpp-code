#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();
        if(m>n) return -1;
        for(int i=0;i<n-m+1;i++){
            if(haystack[i]==needle[0]){
                bool flag=true;
                for(int j=0;j<m;j++){
                    if(haystack[j+i]!=needle[j]){
                        flag=false;
                        break;
                    }
                }
                if(flag==true) return i;
            }
        }
    return -1;
    }
};

int main() {
    Solution sol;
    string haystack = "hello";
    string needle = "ll";
    int result = sol.strStr(haystack, needle);
    cout << "The first occurrence of \"" << needle << "\" in \"" << haystack << "\" is at index: " << result << endl;
    return 0;
}