#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        vector<int>v(4);
        for(int i=0;i<4;i++){  
        v[i]=num%10;
        num/=10;
        }
        sort(v.begin(),v.end());
        int nums1=v[0]*10+v[2];
        int nums2=v[1]*10+v[3];
        return nums1+nums2;
    }
};

int main() {
    Solution sol;
    int num = 2932;
    cout << "Minimum sum of two numbers formed by rearranging digits of " << num << " is: " << sol.minimumSum(num) << endl;
    return 0;
}
