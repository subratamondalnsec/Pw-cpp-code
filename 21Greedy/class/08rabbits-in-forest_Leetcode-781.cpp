//https://leetcode.com/problems/rabbits-in-forest/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {//m1
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>m;
        for(int i :answers) m[i]++;
        int ans=0;
        for(auto x : m){
            int freq=x.second;
            while(freq!=0){
                if(x.first+1>=freq){
                    ans+=(x.first+1);
                    freq=0;
                } 
                else{
                    ans+=(x.first+1);
                    freq-=(x.first+1); 
                }
            }
            
        }
        return ans;
    }
}; 

class Solution {//m2
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>m;
        int ans=0;
        for(int i :answers){
           if(!m[i+1]){
                ans+=i+1;
                if(i==0) continue;
                m[i+1]=1;
           }
           else{
            m[i+1]++;
            int key=i+1;
            int val=m[key];
            if(key==val) m.erase(key);
           }
        }
       
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Example test case
    vector<int> answers = {1, 1, 2};
    
    int result = solution.numRabbits(answers);
    
    // Output the result
    cout << "Number of rabbits: " << result << endl;
    
    return 0;
}
