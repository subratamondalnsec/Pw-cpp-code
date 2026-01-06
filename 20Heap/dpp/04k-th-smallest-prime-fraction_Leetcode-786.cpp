#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {//m1
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {//t.c=o(n^2logk)
        priority_queue<pair<double,pair<int,int>>> pq;
        for(int i = 0; i < arr.size() - 1; i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                double fraction = (double) arr[i] / arr[j];
                pq.push({fraction, {arr[i], arr[j]}});
                if(pq.size() > k) pq.pop();
            }
        }
        return {pq.top().second.first, pq.top().second.second};
    }
};

class Solution {//m2
public:
    typedef pair<double, pair<int, int>> dip;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) { //t.c=O(n log n + k log n)
        int n = arr.size();//s.c=O(n);
        priority_queue<dip, vector<dip>, greater<dip>> pq;
        // Push initial fractions arr[i] / arr[n-1] into the priority queue
        for (int i = 0; i < n - 1; i++) pq.push({(double) arr[i] / arr[n-1], {i, n-1}});

        // Extract the smallest fractions k-1 times
        for (int i = 0; i < k - 1; i++) {
            auto ele = pq.top();
            pq.pop();
            
            // If there are more fractions with arr[ele.second.first]
            if (ele.second.first < ele.second.second - 1) {
                double fraction = (double) arr[ele.second.first] / arr[ele.second.second - 1];
                pq.push({fraction, {ele.second.first, ele.second.second - 1}});
            }
        }
        
        return {arr[pq.top().second.first], arr[pq.top().second.second]};
    }
};

int main() {
    Solution sol;

    // Test case 1: Small array of primes
    vector<int> arr1 = {1, 2, 3, 5};
    int k1 = 3;
    vector<int> result1 = sol.kthSmallestPrimeFraction(arr1, k1);
    cout << "The " << k1 << "-th smallest fraction is: " 
         << result1[0] << "/" << result1[1] << endl;

    // Test case 2: Larger array of primes
    vector<int> arr2 = {1, 7, 23, 29, 47};
    int k2 = 5;
    vector<int> result2 = sol.kthSmallestPrimeFraction(arr2, k2);
    cout << "The " << k2 << "-th smallest fraction is: " 
         << result2[0] << "/" << result2[1] << endl;

    return 0;
}
