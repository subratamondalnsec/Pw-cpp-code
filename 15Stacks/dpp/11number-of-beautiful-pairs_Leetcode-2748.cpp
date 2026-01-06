#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hcf(int a,int b){
        if(a==0) return b;
        else return hcf(b%a,a);
    }
    bool sbeautiful(int a,int b){
        while(a>=10) a/=10;
        b=b%10;
        if(hcf(a,b)==1) return true;
        else return false;
    }
    int countBeautifulPairs(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(sbeautiful(nums[i],nums[j])) count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {12, 34, 56, 78, 91}; // Example input
    
    int result = sol.countBeautifulPairs(nums);
    cout << "Number of beautiful pairs: " << result << endl;
    
    return 0;
}

