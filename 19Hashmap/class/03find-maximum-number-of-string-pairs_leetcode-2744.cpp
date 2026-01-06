#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> // for reverse function

using namespace std;

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& arr) {
        int n = arr.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            string rev = arr[i];
            reverse(rev.begin(), rev.end());
            for (int j = i + 1; j < n; j++) {
                if (rev == arr[j]) count++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& arr) {
        int n=arr.size();
        int count =0;
        unordered_set<string> s;
        for(int i=0;i<n;i++){
            s.insert(arr[i]);
        }
        for(int i=0;i<n;i++){
            string rev=arr[i];
            reverse(rev.begin(),rev.end());
            if(s.find(rev)!=s.end() && arr[i]!=rev){
                count++;
                s.erase(arr[i]);
            }
        }
        return count;
    }
};

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& arr) {
        int n=arr.size();
        int count =0;
        unordered_set<string> s;
        for(int i=0;i<n;i++){
            string rev=arr[i];
            reverse(rev.begin(),rev.end());
            if(s.find(rev)!=s.end() ) count++;
            else s.insert(arr[i]);
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<string> arr = {"abc", "cba", "xyz", "zyx", "pqr"};

    // Call the function and print the result
    int result = sol.maximumNumberOfStringPairs(arr);
    cout << "The maximum number of string pairs is: " << result << endl;

    return 0;
}
