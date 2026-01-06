#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        int n = nums.size();
        unordered_map<int,int> mp; // for late deletion
        priority_queue<int> maxh; // max heap for lower half
        priority_queue<int, vector<int>, greater<int>> minh; // min heap for upper half

        //first insert the element upto the size of window in maxHeap
        for(int i=0;i<k;i++) {
            maxh.push(nums[i]);
        }
        //Now to balance the size of maxHeap and minHeap, insert half elements in minHeap
         for(int i=0;i<(k/2);i++) {
            minh.push(maxh.top());
            maxh.pop();
        }
        // always try to main the middle element on the top of maxh heap
        // if we have even elements in both the heaps, median is avg of top of both heaps
        for(int i=k;i<n;i++) {
            if(k%2 != 0) { // if k is odd, we will have median on the top of maxheap
                medians.push_back(maxh.top()*1.0);
            }
            else { // if k is even
                medians.push_back(((double)maxh.top()+(double)minh.top())/2.0);
            }
            int p=nums[i-k], q=nums[i]; // 
            // we need to remove p and add q;
            // we will delete p when it will come on the top
            // to keep track we will maintain map
            int balance = 0; // keep heaps in balance, for correct ans
            // we decrese balance when remove elements from maxh, so basically if balance<0 it means maxheap has lesser elemets the minheap
            // removing p or adding p to map to delete it later
            if(p<=maxh.top()) { // p is in maxheap
                balance--;
                if(p==maxh.top())
                    maxh.pop();
                else
                    mp[p]++;
            }
            else { // p is min heap
                balance++;
                if(p == minh.top())
                    minh.pop();
                else
                    mp[p]++;
            }
            
            // inserting q to the right heap
            if(!maxh.empty() and q<=maxh.top()) { // pushing q to maxheap
                maxh.push(q);
                balance++;
            }
            else { // pushing q to minheap
                minh.push(q);
                balance--;
            }
            
            // balancing both the heaps
            if(balance<0) {
                maxh.push(minh.top());
                minh.pop();
            }
            else if(balance>0) {
                minh.push(maxh.top());
                maxh.pop();
            }
            
            // removing top elements if they exist in our map(late deletion)
            while(!maxh.empty() and mp[maxh.top()]) {
                mp[maxh.top()]--;
                maxh.pop();
            }
            while(!minh.empty() and mp[minh.top()]) {
                mp[minh.top()]--;
                minh.pop();
            }
        }
        if(k%2 != 0) {
            medians.push_back(maxh.top()*1.0);
        }
        else {
            medians.push_back(((double)maxh.top()+(double)minh.top())/2.0);
        }
        return medians;
    }
};
int main() {
    vector<int> nums = {1, 2, 3, 4, 2, 3, 1, 4, 2};
    int k = 3;
    Solution sol;
    vector<double> result = sol.medianSlidingWindow(nums, k);

    cout << "Medians: ";
    for (double median : result) {
        cout << median << " ";
    }
    cout << endl;

    return 0;
}