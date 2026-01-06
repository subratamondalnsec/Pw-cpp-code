#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        for (int i = 0; i < arr1.size(); i++) m[arr1[i]]++;
        int k = 0;
        for (int i = 0; i < arr2.size(); i++) {
            if (m.find(arr2[i]) != m.end()) {
                for (int j = 0; j < m[arr2[i]]; j++) {
                    arr1[k++] = (arr2[i]);
                }
                m.erase(arr2[i]);
            }
        }
        for (auto ele : m) {
            int freq = ele.second;
            for (int i = 0; i < freq; i++) arr1[k++] = (ele.first);
        }
        return arr1;
    }
};

class Solution {//m2
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int freq[1001]={0};
        for(int i=0;i<arr1.size();i++) freq[arr1[i]]++;
        int k=0;
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<freq[arr2[i]];j++){
                arr1[k++]=(arr2[i]);
            }
            freq[arr2[i]]=0;
        }
        for(int i=0;i<1001;i++){
            while(freq[i]>0){
                arr1[k++]=i;
                freq[i]--;
            }
        }
        return arr1;
    }
};

int main() {
    Solution sol;
    
    // Example arrays
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};
    
    // Call the relativeSortArray function
    vector<int> result = sol.relativeSortArray(arr1, arr2);
    
    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
