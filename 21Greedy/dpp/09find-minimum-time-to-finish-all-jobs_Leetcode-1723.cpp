#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {//Backtracking + Binary Search
public:
    bool canDistribute(vector<int>& jobs, vector<int>& workers, int idx, int limit) {
        if (idx >= jobs.size()) return true; // All jobs are assigned.

        for (int i = 0; i < workers.size(); ++i) {
            if (workers[i] + jobs[idx] <= limit) {
                workers[i] += jobs[idx]; // Assign job to worker `i`.
                if (canDistribute(jobs, workers, idx + 1, limit)) return true;
                workers[i] -= jobs[idx]; // Backtrack.
            }

            // If this worker didn't have any jobs yet, break to prevent redundant permutations.
            if (workers[i] == 0) break;
        }

        return false;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        int start = *max_element(jobs.begin(), jobs.end());
        int end = accumulate(jobs.begin(), jobs.end(), 0);
        int ans = end;

        while (start <= end) {
            int mid = (start + end) / 2;
            vector<int> workers(k, 0); // Each worker's current load.
            if (canDistribute(jobs, workers, 0, mid)) {
                ans = mid; // Update the answer.
                end = mid - 1; // Try for a smaller feasible time.
            } else {
                start = mid + 1; // Increase time if current `mid` is not feasible.
            }
        }

        return ans;
    }
};
int main() {
    vector<int> jobs = {1, 2, 4, 7, 8};
    int k = 2;
    
    Solution solution;
    int result = solution.minimumTimeRequired(jobs, k);
    
    cout << "Minimum time required: " << result << endl;
    return 0;
}