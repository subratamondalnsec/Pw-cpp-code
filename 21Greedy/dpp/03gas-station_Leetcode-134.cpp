#include <iostream>
#include <vector>
#include <numeric> // for accumulate function
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int g = accumulate(gas.begin(), gas.end(), 0);
        int c = accumulate(cost.begin(), cost.end(), 0);
        if (c > g) return -1;

        int start = 0, curr = 0;
        for (int i = 0; i < gas.size(); i++) {
            if (curr < 0) {
                start = i;
                curr = 0;
            }
            curr += (gas[i] - cost[i]);
        }
        return start;
    }
};

int main() {
    int n;
    cout << "Enter the number of gas stations: ";
    cin >> n;

    vector<int> gas(n), cost(n);
    cout << "Enter the gas available at each station: ";
    for (int i = 0; i < n; ++i) {
        cin >> gas[i];
    }

    cout << "Enter the cost to travel to the next station: ";
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    Solution solution;
    int result = solution.canCompleteCircuit(gas, cost);

    if (result == -1) {
        cout << "It's not possible to complete the circuit." << endl;
    } else {
        cout << "You can start at station " << result << " to complete the circuit." << endl;
    }

    return 0;
}
