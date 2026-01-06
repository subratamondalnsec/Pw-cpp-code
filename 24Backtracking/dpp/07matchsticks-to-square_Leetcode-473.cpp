/* problem link : https://leetcode.com/problems/matchsticks-to-square/
By subrata mondal */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(vector<int>& matchsticks,vector<bool>&visit,int target,int t,int p,int idx){
        if(p==4) return true;
        if(t==0) return f(matchsticks,visit,target,target,p+1,0);
        if(t<0) return false;
        if(idx>matchsticks.size()) return false;
        for(int i=idx;i<matchsticks.size();i++){
            if(!visit[i] && t-matchsticks[i]>=0){
                visit[i]=true;
                if(f(matchsticks,visit,target,t-matchsticks[i],p,i+1)) return true;
                visit[i]=false;
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(int ele : matchsticks){
            sum+=ele;
        }
        if(sum%4!=0) return false;
        sort(matchsticks.rbegin(),matchsticks.rend());
        vector<bool>visit(matchsticks.size(),0);
        return f(matchsticks,visit,sum/4,sum/4,0,0);
    }
};

class Solution {
public:
    
    bool dfs(vector<int> matchsticks, int target, vector<int> &sides, int idx){
        // base case
        if(idx == matchsticks.size()){
            if(sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3]){
                return true;
            }
            return false;
        }
        for(int i = 0; i < 4; i++){
            if (sides[i] + matchsticks[idx] > target){  //optimization - 1
                continue;
            }  
            int j = i - 1;  //optimization - 3
            while (j>=0){
                if(sides[j] == sides[i]){
                    break;
                }
                j --;
            }
            if(j != -1){
                continue;
            }        
            sides[i] += matchsticks[idx];
            
            if( dfs(matchsticks, target, sides, idx+1) ){
                return true;
            }
            sides[i] -= matchsticks[idx];
        }        
        return false;        
    }   
    bool makesquare(vector<int>& matchsticks) {  
        int sum = 0;
        for(int i = 0; i < matchsticks.size() ; i++){
            sum += matchsticks[i];
        }
        
        int target = sum / 4;
        vector<int> sides(4,0);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // optimization 2
        return dfs(matchsticks, target, sides, 0);
    }
};

int main() {
    Solution solution;

    // Example test case 1
    vector<int> matchsticks1 = {1, 1, 2, 2, 2};
    if (solution.makesquare(matchsticks1)) {
        cout << "Yes, it's possible to form a square!" << endl;
    } else {
        cout << "No, it's not possible to form a square!" << endl;
    }

    // Example test case 2
    vector<int> matchsticks2 = {3, 3, 3, 3, 4};
    if (solution.makesquare(matchsticks2)) {
        cout << "Yes, it's possible to form a square!" << endl;
    } else {
        cout << "No, it's not possible to form a square!" << endl;
    }

    // Example test case 3
    vector<int> matchsticks3 = {5, 5, 5, 5};
    if (solution.makesquare(matchsticks3)) {
        cout << "Yes, it's possible to form a square!" << endl;
    } else {
        cout << "No, it's not possible to form a square!" << endl;
    }

    return 0;
}
