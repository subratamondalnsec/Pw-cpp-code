#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;
        for(int i=0;i<s.length();i++){
            map1[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            map2[t[i]]++;
        }
        for(auto ele : map1){
            char ch=ele.first;
            int freq=ele.second;
            if(map2.find(ch)!=map2.end()){
                int freq2=map2[ch];
                if(freq!=freq2) return false;
            }
            else return false;
        }
        return true;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> map1;
        for(int i=0;i<s.length();i++){
            map1[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            char ch=t[i];
            if(map1.find(ch)!=map1.end()){
                map1[ch]--;
                if(map1[ch]==0) map1.erase(ch);
            }
            else return false;
        }
        if(map1.size()>0) return false;
        return true;
    }
};

int main() {
    Solution solution;
    
    string s = "anagram";
    string t = "nagaram";

    bool result = solution.isAnagram(s, t);

    if (result) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}