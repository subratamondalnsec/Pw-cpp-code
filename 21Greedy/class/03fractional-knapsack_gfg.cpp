//https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <iostream>
#include <algorithm> // for std::sort
using namespace std;

// Define the Item structure
struct Item {
    int value;
    int weight;
    // Constructor to initialize an Item object
    Item(int value, int weight) {
        this->value = value;
        this->weight = weight;
    }
    // Default constructor
    Item() {}
};

// Comparator function to sort items by value-to-weight ratio
bool cmp(Item &p1, Item &p2) {
    double r1 = (p1.value * 1.0) / (p1.weight * 1.0);
    double r2 = (p2.value * 1.0) / (p2.weight * 1.0);
    return r1 > r2;
}

class Solution {
  public:
    double fractionalKnapsack(int W, Item arr[], int n) {
        // Sort items by value/weight ratio
        sort(arr, arr + n, cmp);
        double result = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i].weight <= W) {
                result += arr[i].value;
                W -= arr[i].weight;
            } else {
                result += ((arr[i].value * 1.0 / arr[i].weight * 1.0) * W * 1.0);
                W = 0;
                break;
            }
        }
        return result;
    }
};

// Main function
int main() {
    // Number of items and capacity of knapsack
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    // Create array of items
    Item arr[n];
    for (int i = 0; i < n; i++) {
        int value, weight;
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> value >> weight;
        arr[i] = Item(value, weight);  // Initializing Item objects
    }

    // Create a solution object and solve the fractional knapsack problem
    Solution sol;
    double maxValue = sol.fractionalKnapsack(W, arr, n);

    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
