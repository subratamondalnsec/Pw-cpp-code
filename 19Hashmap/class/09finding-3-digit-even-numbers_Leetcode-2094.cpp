#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) {
        vector<int> ans;
        unordered_map<int,int>m;
        for(int ele : arr) m[ele]++;
        for(int i=100;i<999;i+=2){
            int a=i%10,b=(i/10)%10,c=(i/100);
            if(m.find(a)!=m.end()){
                m[a]--;
                if(m[a]==0) m.erase(a);
                if(m.find(b)!=m.end()){
                    m[b]--;
                    if(m[b]==0) m.erase(b);
                    if(m.find(c)!=m.end()) ans.push_back(i);
                    m[b]++;
                }
                m[a]++;
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {2, 1, 3, 0};  // Example input array
    
    // Debug log for the input array
    cout << "Input array: ";
    for (int ele : arr) {
        cout << ele << " ";
    }
    cout << endl;
    
    vector<int> result = sol.findEvenNumbers(arr);
    
    // Output the result
    cout << "Even numbers that can be formed: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}