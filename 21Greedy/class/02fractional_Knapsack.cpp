#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool cmp(pair<int,int>&p1,pair<int,int>&p2){
    double r1=(p1.first*1.0)/(p1.second*1.0);
    double r2=(p2.first*1.0)/(p2.second*1.0);
     return r1>r2;
    }
double fractionKnapsack(vector<int>&profit,vector<int>& weight,int n,int W){
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++) v.push_back({profit[i],weight[i]});
    sort(v.begin(),v.end(),cmp);
    double result=0;
    for(int i=0;i<n;i++){
        if(v[i].second<=W){
            result+=v[i].first;
            W-=v[i].second;
        }
        else{
            result+=((v[i].first*1.0/v[i].second*1.0)*W*1.0);
            W=0;
            break;
        }
    }
    return result;
}
int main(){
    vector<int>profit={60,100,120};
    vector<int> weight={10,20,30};
    int w=50,n=3;
    cout<<fractionKnapsack(profit,weight,n,w)<<endl;
    return 0;
}