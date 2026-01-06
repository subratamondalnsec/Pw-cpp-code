#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int k=minutes;
     int n=customers.size();
        int prevloss=0;
        for(int i=0;i<k;i++){
            if(grumpy[i]==1) prevloss+=customers[i];
        }
        int maxloss= prevloss;
        int maxidx=0;
        int i=1;
        int j=k;
        while(j<n){
                int currloss=prevloss;
                if(grumpy[j]==1) currloss+=customers[j];
                if(grumpy[i-1]==1) currloss-=customers[i-1];
                if(maxloss<currloss){
                maxloss=currloss;
                maxidx=i;
            }
            prevloss=currloss;
            i++;
            j++;
        }
        for(int i=maxidx;i<maxidx+k;i++){
            grumpy[i]=0;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) sum+=customers[i];
        }
        return sum;
    }
};
int main() {
    Solution solution;
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;
    
    int result = solution.maxSatisfied(customers, grumpy, minutes);
    cout << "Maximum number of satisfied customers: " << result << endl;

    return 0;
}