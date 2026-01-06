#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;  
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        unordered_set<int> set;
        for(int i = 0; i < arr.size(); i++) {
            map[arr[i]]++;
        }
        for(auto ele : map) {
            int freq = ele.second;
            if(set.find(freq) == set.end()) set.insert(freq);
            else return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    bool result1 = solution.uniqueOccurrences(arr1);
    cout << "Test case 1: " << (result1 ? "True" : "False") << endl;
    
    // Test case 2
    vector<int> arr2 = {1, 2};
    bool result2 = solution.uniqueOccurrences(arr2);
    cout << "Test case 2: " << (result2 ? "True" : "False") << endl;
    
    // Test case 3
    vector<int> arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    bool result3 = solution.uniqueOccurrences(arr3);
    cout << "Test case 3: " << (result3 ? "True" : "False") << endl;

    return 0;
}
