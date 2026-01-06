#include <bits/stdc++.h>
using namespace std;
class solution{
public:
int bestclosingTime(string customers){
    int n=customers.length();
    int pre[n+1];//no of N before kth hour
    int suf[n+1];//no of y after and including kth hour
    pre[0]=0;
    for(int i=0;i<n;i++){
       // int count=0;
        //if(customers[i]=='N') count++;
        pre[i+1]=pre[i]+((customers[i]=='N')?1:0);  //count;
    }
    suf[n]=0;
    for(int i=n-1;i>=0;i--){
        suf[i]=suf[i+1]+((customers[i]=='Y')?1:0);
    }
    int minpenalty=INT_MAX;//n+5
       for(int i=0;i<=n;i++){
        pre[i]+=suf[i];
        int pen =pre[i];
        minpenalty=min(minpenalty,pen);
}
    for(int i=0;i<=n;i++){
        int pen=pre[i];
        if(pen==minpenalty) return i;
    }
    return n;
  }
};

class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length();
        int pre[n+1],suf[n+1];
        suf[n]=0;
        for(int i=n-1;i>=0;i--){
            suf[i]=suf[i+1]+(customers[i]=='Y' ? 1 : 0);
        }
        pre[0]=0;
        int minpenalty=INT_MAX;
        int mintime=n;
        for(int i=0;i<=n;i++){
            if(i!=n) pre[i+1]=pre[i]+(customers[i]=='N' ? 1 : 0);
            pre[i]=pre[i]+suf[i];
            if(minpenalty>pre[i]){
                minpenalty=pre[i];
                mintime=i;
            }
        }
        return mintime;
    }
};

int main() {
    string customers = "YNYYNYNNNN";
    
    solution sol;
    int bestTime = sol.bestclosingTime(customers);
    
    cout << "Best closing time index: " << bestTime << endl;
    
    return 0;
}