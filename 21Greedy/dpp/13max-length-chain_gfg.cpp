#include<bits/stdc++.h>
using namespace std;
struct val{
	int first;
	int second;
};
bool cmp(val &a ,val &b){
    return a.second< b.second;
}
class Solution{
public:
    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n){
        int result=1;
        sort(p,p+n,cmp);
        int lastval=p[0].second;
        for(int i=1;i<n;i++){
            if(p[i].first>lastval){
                result++;
                lastval=p[i].second;
            }
            
        }
        return result;
    }
};
int main() {
    Solution solution;
	val arr[] = {{5 , 24} , {39 ,60} , {15 ,28} , {27 ,40} , {50 ,90}};
	int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Max length chain : "<<solution.maxChainLen(arr, n);
	return 0;
}