//https://www.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

// Comparator function to sort in descending order
bool cmp(int x, int y) {
    return x > y;
}

class Solution {
public:
    int minimumCostOfBreaking(vector<int> var, vector<int> hor, int M, int N) {
        // Sort both vertical and horizontal cuts in descending order
        sort(var.begin(), var.end(), cmp);
        sort(hor.begin(), hor.end(), cmp);

        int var_cart = 1;  // Initially, we have one vertical segment
        int hor_cart = 1;  // Initially, we have one horizontal segment
        int h = 0, v = 0;
        int ans = 0;

        // Use a greedy approach to add the larger cost cut first
        while (h < hor.size() && v < var.size()) {
            if (var[v] > hor[h]) {
                ans += (var[v] * var_cart);
                v++;
                hor_cart++;  // Increase the number of horizontal pieces
            } else {
                ans += (hor[h] * hor_cart);
                h++;
                var_cart++;  // Increase the number of vertical pieces
            }
        }

        // Process remaining horizontal cuts
        while (h < hor.size()) {
            ans += (hor[h] * hor_cart);
            h++;
            var_cart++;
        }

        // Process remaining vertical cuts
        while (v < var.size()) {
            ans += (var[v] * var_cart);
            v++;
            hor_cart++;
        }

        return ans;
    }
};

// Main function
int main() {
    int M, N;  // Dimensions of the chocolate (M-1 vertical cuts, N-1 horizontal cuts)
    cout << "Enter the number of vertical cuts (M-1): ";
    cin >> M;
    cout << "Enter the number of horizontal cuts (N-1): ";
    cin >> N;

    vector<int> var(M-1);  // Costs of vertical cuts
    vector<int> hor(N-1);  // Costs of horizontal cuts

    // Input the costs for vertical cuts
    cout << "Enter the costs of vertical cuts: ";
    for (int i = 0; i < M - 1; i++) {
        cin >> var[i];
    }

    // Input the costs for horizontal cuts
    cout << "Enter the costs of horizontal cuts: ";
    for (int i = 0; i < N - 1; i++) {
        cin >> hor[i];
    }

    // Create an instance of the solution class
    Solution sol;
    
    // Calculate and print the minimum cost of breaking the chocolate
    int result = sol.minimumCostOfBreaking(var, hor, M, N);
    cout << "Minimum cost of breaking the chocolate: " << result << endl;

    return 0;
}
