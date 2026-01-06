//  #include <bits/stdc++.h>// coins are repeated
//  using namespace std;
// void combination(int arr[],int n, vector<int>v,int target){
//    if(target==0){
//     for(int i=0;i<v.size();i++){
// cout<<v[i]<<" ";
// //cout<<endl;
//     }
//     cout<<endl;
//     return;
//     }
//     if(target<0) return;
//    for(int i=0;i<n;i++){
//      v.push_back(arr[i]);
//     //cout<<i<<"  start push "<<arr[i]<<endl;
//     combination(arr,n,v,target-arr[i]);
//   //cout<<i<<"  end pop "<<arr[i]<<endl;
//     v.pop_back(); 
//     }  
// }
// int main(){
//     int arr[]={2,3,5};
//      int n=sizeof(arr)/sizeof(arr[0]);
//      vector<int>v;
//      combination(arr,n,v,8);
// }
#include <bits/stdc++.h>// coins are not repeated
using namespace std;
void combination(int arr[],int n, vector<int>v,int target,int idx){
   if(target==0){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return;
    }
    if(target<0) return;
   for(int i=idx;i<n;i++){
     v.push_back(arr[i]);
    // cout<<i<<"  start push "<<arr[i]<<"-- "<< idx<<endl;
    combination(arr,n,v,target-arr[i],i);//change i=> idx 
   //cout<<i<<"  end pop "<<arr[i]<<"-- "<< idx<<endl;
    v.pop_back(); 
    }  
}
int main(){
    int arr[]={2,3,5};
     int n=sizeof(arr)/sizeof(arr[0]);
     vector<int>v;
     combination(arr,n,v,8,0);
}
/* leet code 39 */
/*#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void combination(vector<vector<int>>& ans, vector<int> v,vector<int>& candidates,int target,int idx){
   if(target==0){
        ans.push_back(v);
        return;
   }
    if(target<0) return;
   for(int i=idx;i<candidates.size() ;i++){
        v.push_back(candidates[i]);
        combination(ans,v,candidates,target-candidates[i],i);
        v.pop_back(); 
    }  
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>>ans;
        vector<int>v;
        combination(ans,v,candidates,target,0);
        return ans;
    }
};*/

/*class Solution {easy method
public:
    void combination(vector<vector<int>>& ans, vector<int> v,
                     vector<int>& candidates, int target, int idx) {
        if(idx>=candidates.size()){
               if (target == 0) ans.push_back(v);
                return;
        }
        if (candidates[idx] <= target) {
            v.push_back(candidates[idx]);
            combination(ans, v, candidates, target - candidates[idx], idx);
            v.pop_back();
        }
        combination(ans, v, candidates, target, idx + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        combination(ans, v, candidates, target, 0);
        return ans;
    }
}; */

/*int main() {
    Solution solution;
    int n, target;
    
    cout << "Enter the number of candidates: ";
    cin >> n;
    vector<int> candidates(n);
    cout << "Enter the candidates: ";
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }
    cout << "Enter the target sum: ";
    cin >> target;
    
    vector<vector<int>> result = solution.combinationSum(candidates, target);
    
    cout << "Combination sums that add up to " << target << " are:" << endl;
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}*/

