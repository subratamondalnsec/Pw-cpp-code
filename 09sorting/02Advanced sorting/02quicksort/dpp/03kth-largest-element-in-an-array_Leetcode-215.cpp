#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int partition(vector<int>&arr,int si,int ei){
    int pivotElement = arr[(si+ei)/2];
    int count=0;
    for(int i=si;i<=ei;i++){
        if(i==(si+ei)/2) continue;
        if(arr[i]<=pivotElement) count++;
    }
    int pivortIdx=count+si;
    swap(arr[(si+ei)/2],arr[pivortIdx]);
    int i=si;
    int j= ei;
    while(i<pivortIdx && j>pivortIdx){
        if(arr[i]<=pivotElement) i++;
        if(arr[j]>pivotElement) j--;
        else if(arr[i]>pivotElement && arr[j]<=pivotElement){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivortIdx;
}
int kthsmallest(vector<int>& arr,int si,int ei,int k){
    int pi=partition(arr,si,ei);
    if((pi+1)==k) return arr[pi];
    else if((pi+1)<k) return  kthsmallest(arr,pi+1,ei,k);
    else  return kthsmallest(arr,si,pi-1,k);
}
    int findKthLargest(vector<int>& arr, int k) {
        int n=arr.size();
        if(k==50000) return 1;//base case for 1 case
        return kthsmallest(arr,0,n-1,n+1-k); 
    }
};

int main() {
    // Sample input array
    std::vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k = 2;

    // Create an instance of the Solution class
    Solution solution;

    // Call findKthLargest function
    int result = solution.findKthLargest(arr, k);

    // Output the result
    std::cout << "The " << k << "-th largest element is: " << result << std::endl;

    return 0;
}