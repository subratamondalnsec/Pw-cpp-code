#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> q;
        queue<int> r;
        queue<int> d;
        for(int i=0;i<s.length();i++){
            q.push(i);
            if(s[i]=='R') r.push(i);
            else d.push(i);
        }
        while(q.size()>1){
            if(s[q.front()]=='X') q.pop();
            else if (s[q.front()]=='R'){
                if(d.size()==0) return "Radiant";
                else{//remove next d
                    s[d.front()]='X';
                    d.pop();
                    q.push(q.front());
                    q.pop();
                    r.push(r.front());
                    r.pop();
                }
            }
            else{//s[q.front()]=='R'
                if(r.size()==0) return "Dire";
                else{//remove next d
                    s[r.front()]='X';
                    r.pop();
                    q.push(q.front());
                    q.pop();
                    d.push(d.front());
                    d.pop();
                }

            }
        }
        if (s[q.front()]=='R')  return "Radiant";
        else return "Dire";

    }
};

int main() {
    Solution sol;

    std::string senate1 = "RD";
    std::string senate2 = "RDD";
    std::string senate3 = "RRDDDR";

    std::cout << "Senate: " << senate1 << " => " << sol.predictPartyVictory(senate1) << std::endl; // Output: Radiant
    std::cout << "Senate: " << senate2 << " => " << sol.predictPartyVictory(senate2) << std::endl; // Output: Dire
    std::cout << "Senate: " << senate3 << " => " << sol.predictPartyVictory(senate3) << std::endl; // Output: Radiant

    return 0;
}
