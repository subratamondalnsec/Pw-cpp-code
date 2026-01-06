//https://leetcode.com/problems/maximum-units-on-a-truck/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// bool cmp(vector<int>& v1, vector<int>& v2) {
//     return v1[1] > v2[1];
// }
class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2) {
        return v1[1] > v2[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        
        int ans = 0;
        for (int i = 0; i < boxTypes.size() && truckSize != 0; i++) {
            if (boxTypes[i][0] <= truckSize) {
                ans += (boxTypes[i][0] * boxTypes[i][1]);
                truckSize -= boxTypes[i][0];
            } else {
                ans += (truckSize * boxTypes[i][1]);
                truckSize = 0;
                break;
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> boxTypes = {{1, 3}, {2, 2}, {3, 1}};
    int truckSize = 4;

    Solution solution;
    int result = solution.maximumUnits(boxTypes, truckSize);

    cout << "Maximum units that can be loaded onto the truck: " << result << endl;

    return 0;
}
