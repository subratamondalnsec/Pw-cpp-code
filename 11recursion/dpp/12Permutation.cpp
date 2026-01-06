#include <iostream>
#include <vector>

using namespace std;

// Recursive function to generate increasing sequences
void generateSequences(int n, int k, int start, vector<int>& sequence) {
    // Base case: if the sequence length is k, print the sequence
    if (sequence.size() == k) {
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    // Recur for each number from `start` to `n`
    for (int i = start; i <= n; ++i) {
        sequence.push_back(i); // Include the current number in the sequence
        generateSequences(n, k, i + 1, sequence); // Recur for the next numbers
        sequence.pop_back(); // Backtrack and remove the current number
    }
}

int main() {
    int n = 5; // First `n` natural numbers
    int k = 3; // Length of the sequence

    vector<int> sequence; // To store the current sequence
    generateSequences(n, k, 1, sequence); // Generate all increasing sequences

    return 0;
}
