#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isvowel(char ch){
    if(ch=='a') return true;
    else if(ch=='e') return true;
    else if(ch=='i') return true;
    else if(ch=='o') return true;
    else if(ch=='u') return true;
    else return false;
}
    int maxVowels(string s, int k) {
        int maxcount=0;
    for(int i=0;i<k;i++){
        if(isvowel(s[i])==true) maxcount++;
    }
    int count = maxcount;
    int i=0,j=k-1;
    while(j<s.size()){
       if(isvowel(s[i])==true) count--;
       i++;
       j++;
       if(isvowel(s[j])==true) count++;
       maxcount=max(maxcount,count);
    }
    return maxcount;
    }
};

int main() {
    Solution sol;
    string s = "abciiidef";
    int k = 3;
    cout << "Maximum number of vowels in any substring of length " << k << " is: " << sol.maxVowels(s, k) << endl;
    return 0;
}