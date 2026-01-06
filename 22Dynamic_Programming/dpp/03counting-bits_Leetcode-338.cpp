#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>result(n+1);
        for(int i=0;i<n+1;i++){
            result[i]=__builtin_popcount(i);
        }
        return result;
    }
};

class Solution {//Tabulation
public:
    vector<int> countBits(int n) {
        vector<int>result(n+1);
        result[0]=0;
        if(n==0) return result;
        for(int i=1;i<n+1;i++){
            if(i%2!=0) result[i]=result[i/2]+1;
            else result[i]=result[i/2];
        }
        return result;
    }
};

int main(){
    Solution solution;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> result = solution.countBits(n);
    cout << " 0 to n the number of 1's " << " is: ";
    for(int i=0;i<=n;i++){
        cout<<result[i]<<" ";
    }
    return 0;
}