#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution{
  public:
    vector<string> winner(string arr[], int n) {
       unordered_map<string, int> m;
       for (int i = 0; i < n; i++) m[arr[i]]++;
       
       string name = "";
       int mval = 0;
       
       for (auto x : m) {
           string key = x.first;
           int val = x.second;
           
           if (mval < val) {
               mval = val;
               name = key;
           } else if (mval == val) {
               if (key < name) name = key;
           }
       }
       
       vector<string> ans;
       ans.push_back(name);
       ans.push_back(to_string(mval));
       
       return ans;
    }
};

int main() {
    int n;
    cout << "Enter the number of votes: ";
    cin >> n;
    
    string arr[n];
    cout << "Enter the names of candidates: \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    Solution obj;
    vector<string> result = obj.winner(arr, n);
    
    cout << "Winner: " << result[0] << "\nVotes: " << result[1] << endl;
    
    return 0;
}
