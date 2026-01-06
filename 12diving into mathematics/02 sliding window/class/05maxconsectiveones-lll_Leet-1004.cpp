#include <bits/stdc++.h>
using namespace std;
class solution{
public:
    int longestOnes(vector<int>& nums,int k){
        int n=nums.size();
        int flips=0,i=0,j=0;
        int maxlen=INT_MIN,len=INT_MIN;
        while(j<n){
            if(nums[j]==1) j++;
            else{
                if(flips<k){
                    flips++;
                    j++;
                }
                else{//flips==k
                    //calculate len
                    len= j-i;
                    maxlen=max(maxlen,len);
                    //i ko just uske aage wale 0 se ek idx aage le jaao
                    while(nums[i]==1) i++;
                    i++;
                    j++;
                }
            }

        }
        len= j-i;
        maxlen=max(maxlen,len);
        return maxlen;
    }
};
int main() {
    solution solution;
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1};
    int k = 2;
    
    int result = solution.longestOnes(nums, k);
    cout << "Maximum length of subarray with at most " << k << " flips: " << result << endl;

    return 0;
}