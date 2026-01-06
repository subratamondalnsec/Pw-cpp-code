/* problem link : https://leetcode.com/problems/matchsticks-to-square/
By subrata mondal */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    void f(int start,int k,vector<int>&temp,int& n){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(start>n) return;
        temp.push_back(start);
        f(start+1,k-1,temp,n);

        temp.pop_back();
        f(start+1,k,temp,n);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        f(1,k,temp,n);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>>ans;
    void f(int start,int k,vector<int>&temp,int& n){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        for(int i=start;i<=n;i++){
            temp.push_back(i);
            f(i+1,k-1,temp,n);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        f(1,k,temp,n);
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    int n1 = 4, k1 = 2;
    vector<vector<int>> result1 = solution.combine(n1, k1);
    cout << "Combinations of " << k1 << " numbers from 1 to " << n1 << ": " << endl;
    for (const auto& combination : result1) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    // Test case 2
    int n2 = 5, k2 = 3;
    vector<vector<int>> result2 = solution.combine(n2, k2);
    cout << "Combinations of " << k2 << " numbers from 1 to " << n2 << ": " << endl;
    for (const auto& combination : result2) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
