 #include <bits/stdc++.h>
using namespace std;
// Helper function to check if a given capacity can ship all weights within the given number of days
 bool check(int mid,vector<int>& a, int days){
        int count =1;
        int m=mid;
         int n=a.size();
         for(int i=0;i<n;i++){
            if(m>=a[i]){
                m-=a[i];
            }
            else{
                count++;
                m=mid;
                m-=a[i];
            }
         }
         if(count>days) return false;
          else return true;
    };
    // Main function to find the minimum capacity to ship within the given number of days
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0,max=INT_MIN;
        for(int i=0;i<n;i++){
            if(max<weights[i]) max=weights[i];
            sum+=weights[i];
        }
        int lo=max;
        int hi=sum;
        int mincap=sum;
        // Binary search for the minimum capacity
        while(lo<=hi){
           int mid=lo+(hi-lo)/2;
            if(check(mid,weights,days)){
                mincap=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return mincap;
    }
    int main() {
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    int result = shipWithinDays(weights, days);
    cout << "Minimum ship capacity to ship within " << days << " days: " << result << endl;

    return 0;
}//t.c =O(n*log(sum-max))
