#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>  v(1001,0);
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            if(v[nums1[i]]==0) v[nums1[i]]=1;
        }
        for(int i=0;i<nums2.size();i++){
            if(v[nums2[i]]==1) {
                ans.push_back(nums2[i]);
                v[nums2[i]]=0;
            }
        }
    return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result = solution.intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}