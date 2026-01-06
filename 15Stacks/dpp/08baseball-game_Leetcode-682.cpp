#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& op) {
        vector<int> v;
        for(auto& x :op){
            if(x=="C") v.pop_back();
            else if(x=="D") v.push_back(2*(v[v.size()-1]));
            else if(x=="+") v.push_back(v[v.size()-1]+v[v.size()-2]);
            else  v.push_back(stoi(x));
        }
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
        }
        return sum;
    }
};
int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Define a vector of operations for testing
    vector<string> ops = {"5", "2", "C", "D", "+"};

    // Call the calPoints function and get the result
    int result = solution.calPoints(ops);

    // Output the result
    cout << "The final score is: " << result << endl;

    return 0;
}