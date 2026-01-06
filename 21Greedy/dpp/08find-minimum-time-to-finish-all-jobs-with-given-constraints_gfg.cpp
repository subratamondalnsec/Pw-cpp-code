// C++ program to find minimum time to finish all jobs with given number of assignees
#include <bits/stdc++.h>
using namespace std;
bool ispossible(int time, int k, int job[], int n){
    int count=1,count_time=0;
    for(int i=0;i<n;){
        if(count_time+job[i]>time){
            count_time=0;
            count++;
        }
        else{
            count_time+=job[i];
            i++;
        }
    }
    return (count<=k);
}
int findMinTime(int K, int T, int job[], int n){
    int start=0,end=0;
    int job_max=INT_MIN;
    for(int i=0;i<n;i++){
        job_max=max(job_max,job[i]);
        end+=job[i];
    } 
    int ans=end;
    while(start<=end){
        int mid=(start+end)/2;
        if(mid>=job_max and ispossible(mid,K,job,n)){
            ans=min(ans,mid);
            end=mid-1;
        }
        else start=mid+1;
    }
    return (ans*T);
}
int main(){
    int job[] = { 10, 7, 8, 12, 6, 8 };
    int n = sizeof(job) / sizeof(job[0]);
    int k = 4, T = 5;
    cout << findMinTime(k, T, job, n) << endl;
    return 0;
}