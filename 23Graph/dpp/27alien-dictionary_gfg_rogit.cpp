/* Problem Link - https://www.geeksforgeeks.org/problems/alien-dictionary/1
 By subrata mondal */

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
  public:
    string findOrder(vector<string> dict, int k) {
        if(k==1){
            string a=dict[0];
            return a;
        }
        int n=dict.size();
        vector<int>ind(k,0);
        vector<list<int> >g(k);
        for(int i=0;i<n-1;i++){
            string s1=dict[i],s2=dict[i+1];
            int j=0,k=0;
            while(j<s1.size() && k<s2.size() && s1[j]==s2[k]) j++, k++;
            if(j==s1.size()) continue;
            g[s1[j]-'a'].push_back(s2[k]-'a');
            ind[s2[k]-'a']++;
        }
        queue<int>q;
        for(int i=0;i<ind.size();i++){
            if(ind[i]==0) q.push(i);
        }
        string s ="";
        while(!q.empty()){
            int i =q.front();
            q.pop();
            s+=(char)(i+'a');
            for(int x : g[i]){
                ind[x]--;
                if(ind[x]==0){
                    q.push(x);
                }
            }
        }
        return s;
    }
};

int main() {
    // Create a solution object
    Solution obj;

    // Input the dictionary
    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
    int k = 4; // Number of distinct characters in the alien language

    // Call the function to find the order
    string order = obj.findOrder(dict, k);

    // Output the result
    cout << "The order of characters in the alien dictionary is: " << order << endl;

    return 0;
}