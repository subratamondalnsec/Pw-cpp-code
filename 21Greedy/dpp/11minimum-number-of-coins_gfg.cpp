#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> minPartition(int N){
        vector<int> arr= { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        vector<int> ans;
        for(int i=arr.size()-1;i>=0;i--){
            while(N>=arr[i]){
                N-=arr[i];
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};
int main(){
    Solution solution;
	int n = 93;
	cout << "Following is minimal"	<< " number of change for " << n << ": ";
	vector<int>result=solution.minPartition(n);
    for(int i : result) cout<<i<<" ";

	return 0;

}