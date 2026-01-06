#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;  // Min-heap to store the largest k elements
    int n;
    // Constructor to initialize KthLargest with k and arr
    KthLargest(int k, vector<int>& arr) {
        n = k;
        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);  // Push each element into the priority queue
            if (pq.size() > n) pq.pop();  // Maintain only k largest elements in the queue
        }
    }
    // Function to add a new element and return the kth largest element
    int add(int val) {
        if (pq.size() < n) pq.push(val);  // If queue has fewer than k elements, push the new value
        else if (pq.top() < val) {
            pq.pop();  // If new value is larger than the smallest in the queue, replace it
            pq.push(val);
        }
        return pq.top();  // Return the kth largest element
    }
};

// Main function to test the KthLargest class
int main() {
    vector<int> arr = {4, 5, 8, 2};  // Example array
    int k = 3;  // We want the 3rd largest element

    KthLargest kthLargest(k, arr);  // Initialize KthLargest object

    // Test the add function
    cout << kthLargest.add(3) << endl;  // returns 4
    cout << kthLargest.add(5) << endl;  // returns 5
    cout << kthLargest.add(10) << endl;  // returns 5
    cout << kthLargest.add(9) << endl;  // returns 8
    cout << kthLargest.add(4) << endl;  // returns 8

    return 0;
}
