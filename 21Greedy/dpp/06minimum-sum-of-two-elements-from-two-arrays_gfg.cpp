#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
  public:
    int minSum(vector<int>& arr1, vector<int>& arr2) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int smin1 = INT_MAX, smin2 = INT_MAX;
        int idx1 = -1, idx2 = -1;
        
        for (int i = 0; i < arr1.size(); i++) {
            // Finding minimum and second minimum in arr1
            if (arr1[i] < min1) {
                smin1 = min1;
                min1 = arr1[i];
                idx1 = i;
            } 
            else if (arr1[i] < smin1) smin1 = arr1[i];

            // Finding minimum and second minimum in arr2
            if (arr2[i] < min2) {
                smin2 = min2;
                min2 = arr2[i];
                idx2 = i;
            } 
            else if (arr2[i] < smin2) smin2 = arr2[i];
        }

        if (idx1 != idx2) return min1 + min2;
        else return min(min1 + smin2, min2 + smin1);
    }
};
int main(){
    
    vector<int> a = {5, 4, 3, 8, 1};
    vector<int> b = {2, 3, 4, 2, 1};
    Solution solution;
    int result = solution.minSum(a, b);
    cout << "Minimum sum of two elements from two arrays such that indexes are not same : "<<result;
    return 0;
}