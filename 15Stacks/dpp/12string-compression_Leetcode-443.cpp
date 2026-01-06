#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& arr) {
        string s="";
        int n=arr.size();
        int i=0,j=0;
        while(j<n){
            if(arr[i]==arr[j]) j++;
            else {
                s+=arr[i];
                int len =j-i;
                if(len!=1) s+=to_string(len);
                i=j;
            }   
        }
        s+=arr[i];
        int len =j-i;
        if(len!=1) s+=to_string(len);
        while(arr.size()>0) arr.pop_back();
        for(int i=0;i<s.length();i++){
            arr.push_back(s[i]);
        }
        return s.length();
    }
};

int main() {
    Solution solution;

    // Test case
    vector<char> arr = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    
    // Call the compress function
    int newLength = solution.compress(arr);
    
    // Output the result
    cout << "Compressed length: " << newLength << endl;
    cout << "Compressed array: ";
    for (int i = 0; i < newLength; i++) {
        cout << arr[i];
    }
    cout << endl;

    return 0;
}