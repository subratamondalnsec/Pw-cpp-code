#include <bits/stdc++.h>
using namespace std;
class solution{
    public:
 bool prime(int n){
    if(n==1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
    int diagonalPrime(vector<vector<int>>& nums){
        int mx=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(prime(nums[i][i])){
                mx=max(mx,nums[i][i]);
            }
            if(prime(nums[i][n-i-1])){
                mx=max(mx,nums[i][n-i-1]);
            }
        }
        return mx;
    }
};
int main() {
    solution solution;
    vector<vector<int>> nums = {
        {2, 3, 5, 7},
        {4, 11, 13, 17},
        {6, 19, 23, 29},
        {8, 31, 37, 41}
    };
    
    int result = solution.diagonalPrime(nums);
    cout << "Maximum prime number in diagonals: " << result << endl;

    return 0;
}