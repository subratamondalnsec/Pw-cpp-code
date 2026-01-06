#include <bits/stdc++.h>
using namespace std;
class solution{
public:
    vector<int> answerQueries(vector<int>& nums,vector<int>& queries){
        int n=nums.size();
        int m=queries.size();
        vector<int> ans(m);
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            nums[i] +=nums[i-1];
        }
        for(int i=0;i<m;i++){
            int maxlen=0;
            int lo=0;
            int hi=n-1;
            while(lo<=hi){//binary seaching
                int mid=lo+(hi-lo)/2;
                if(nums[mid]>queries[i]) hi=mid-1;
                else{//nums[mid]<=queries[i]
                    maxlen= mid+1;
                    lo=mid+1;
                }
            }
            ans[i]=maxlen;
        }
        return ans;
    }
};
int main() {
    solution sol;
    
    // Example usage
    vector<int> nums = {1, 3, 4, 8};
    vector<int> queries = {2, 6, 9};
    
    vector<int> result = sol.answerQueries(nums, queries);
    
    // Print the result
    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}