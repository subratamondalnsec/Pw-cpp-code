//https://leetcode.com/problems/construct-string-with-repeat-limit/

#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

class Solution {//m1
public:
    string repeatLimitedString(string s, int k) {
        unordered_map<char, int> m;
        for (char i : s) m[i]++;  // Count frequency of each character

        // Max heap (priority queue) to store characters by frequency, with characters sorted in descending lexicographical order
        priority_queue<pair<char, int>> pq;
        for (auto ele : m) pq.push(ele);

        string ans = "";

        while (!pq.empty() && (ans.empty() || ans.back() != pq.top().first)) {
            auto ele = pq.top();
            pq.pop();

            if (ele.second > k && (ans.empty() || ans.back() != ele.first)) {
                // Add up to k occurrences of the current character
                for (int i = 0; i < k; i++) ans += ele.first;
                ele.second -= k;

                if (pq.empty()) break;  // No more characters to insert between the current character's sequence
                
                // Add one occurrence of the next largest character
                ans += pq.top().first;
                auto sele = pq.top();
                pq.pop();

                pq.push(ele);  // Push the current character back if it has remaining frequency
                sele.second--;

                // Push the next largest character back if it still has remaining occurrences
                if (sele.second != 0) pq.push(sele);

            } else if (ele.second <= k && (ans.empty() || ans.back() != ele.first)) {
                // Add all remaining occurrences of the current character if it's <= k
                for (int i = 0; i < ele.second; i++) ans += ele.first;
            }
        }

        return ans;
    }
};

class Solution {//m2
public:
    string repeatLimitedString(string s, int k) {
        unordered_map<char,int> m;
        for(char i : s) m[i]++;
        priority_queue< pair<char,int> >pq;
        for(auto ele : m) pq.push(ele);
        string ans="";
        while(!pq.empty() && (ans.length()==0 || ans[ans.length()-1]!=pq.top().first)){
            auto ele = pq.top();
            pq.pop();
            int  len=min(k,ele.second);
            for(int i=0;i<len;i++) ans+=ele.first;
            pair<char,int> sele;
            if(ele.second-len>0){
                if(!pq.empty()){
                    sele=pq.top();
                    pq.pop();
                    ans+=sele.first;
                }
                else return ans;
                if(sele.second-1>0) pq.push({sele.first,sele.second-1});
                pq.push({ele.first,ele.second-len});
            }
         
        }
        return ans;
    }
};

// Main function to test the repeatLimitedString function
int main() {
    Solution sol;
    
    string s;
    int k;

    // Input string and repeat limit
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the repeat limit k: ";
    cin >> k;

    // Get the result from the function
    string result = sol.repeatLimitedString(s, k);

    // Output the result
    cout << "Resulting string: " << result << endl;

    return 0;
}
