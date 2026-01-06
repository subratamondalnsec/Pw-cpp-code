#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        long long sum = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < arr.size(); i++) 
            pq.push(arr[i]);
        while (pq.size() > 1) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(x + y);
            sum += (x + y);
        }
        return sum;
    }
};

int main() {
    // Example: vector of ropes' lengths
    vector<long long> ropes = {4, 3, 2, 6};
    
    Solution sol;
    long long result = sol.minCost(ropes);
    
    // Output the result
    cout << "Minimum cost to connect ropes: " << result << endl;
    
    return 0;
}
