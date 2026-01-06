//https://leetcode.com/problems/boats-to-save-people/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * T.c=O(nlogn)
 * s.c=O(logn)
 */
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int boat = 0;
        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                i++;
                j--;
            } else {
                j--;
            }
            boat++;
        }
        return boat;
    }
};

int main() {
    Solution sol;
    vector<int> people = {3, 2, 2, 1}; // example input
    int limit = 3; // example weight limit

    int result = sol.numRescueBoats(people, limit);

    cout << "Minimum number of boats required: " << result << endl;

    return 0;
}
