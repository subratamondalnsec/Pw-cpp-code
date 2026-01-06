#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
         int n=satisfaction.size();
    sort(satisfaction.begin(),satisfaction.end());
    int suf[n];
    suf[n-1]=satisfaction[n-1];
    for(int i=n-2;i>=0;i--){
        suf[i]=suf[i+1]+satisfaction[i];
    }//find the pivot idx
    int idx=-1;
    for(int i=0;i<n;i++){
        if(suf[i]>=0){
            idx=i;
            break;
        }
    }//max sum of like-time coefficient
    if(idx==-1) return 0;
    int x=1;
    int maxsum=0;
    for(int i=idx; i<n;i++){
        maxsum+=(satisfaction[i]*x);
        x++;
    }
    return maxsum;
    }
};

class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        int idx=-1;
        if(v[0]<0){
            int suf[n];
            suf[n-1]=v[n-1];
            for(int i=n-2;i>=0;i--){
                suf[i]=suf[i+1]+v[i];
            }
            for(int i=0;i<n;i++){
                if(suf[i]>=0){
                    idx=i;
                    break;
                }
            }
            if(idx==-1) return 0;
        }
        if(v[0]>=0) idx=0;
        int x=1;
        int maxsum=0;
        for(int i =idx;i<n;i++){
            maxsum+=v[i]*x;
            x++;
        }
        return maxsum;
    }
};

int main() {
    Solution sol;
    vector<int> satisfaction = {-1, 2, 3, 4, -5};
    int maxSatisfaction = sol.maxSatisfaction(satisfaction);
    cout << "Maximum Satisfaction: " << maxSatisfaction << endl;
    
    return 0;
}