#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool divisorGame(int n) {
        if(n<=1) return false;
        for(int x=1;x<n;x++){
            if(n%x==0) return !divisorGame(n-x);//Bob case
        }
        return false;
    }
};
class Solution {
public:
    bool divisorGame(int n) {
        if(n%2==0) return true;
        else return false;
    }
};
int main(){
    int n;
    cout<<"Enter a Number : ";
    cin>>n;
    Solution sol;
    bool result=sol.divisorGame(n);
    cout<< "Alice ";
    (result) ? cout<<"win " : cout<<"lose ";
    cout<< "the game."<<endl;
}