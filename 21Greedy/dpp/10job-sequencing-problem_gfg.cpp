#include<bits/stdc++.h>
using namespace std;
struct Job{
    char id;
    int dead;
    int profit;
};
bool cmp(Job &a, Job &b){
    return (a.profit> b.profit);
}
class Solution {
    public:   
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) { 
        sort(arr,arr+n,cmp);
        int max_deadline=0;
        for(int i=0;i<n;i++){
            max_deadline=max(max_deadline,arr[i].dead);
        }
        int countjob=0,job_profit=0;
        vector<int> result(max_deadline+1,-1);
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(result[j]==-1){
                    result[j]=i;
                    countjob++;
                    job_profit+=arr[i].profit;
                    break;
                }
            }
        }
        return {countjob,job_profit};
    } 
};
int main() {
    Solution solution;
	Job arr[] = {{ 'a', 2, 100 }, { 'b', 1, 19 }, { 'c', 2, 27 },{ 'd', 1, 25 },{ 'e', 3, 15 }};
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int>result=solution.JobScheduling(arr, n);
    for(int i : result) cout<<i<<" ";
	return 0;
}