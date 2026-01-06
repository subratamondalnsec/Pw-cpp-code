#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n){
        vector<int>arr(n+1);
        int i5,i2,i3;
        i5=i2=i3=1;
        arr[1]=1;
        for(int i=2;i<=n;i++){
            int i2ugly=arr[i2]*2;
            int i3ugly=arr[i3]*3;
            int i5ugly=arr[i5]*5;
            int minuglyNum=min({i2ugly,i3ugly,i5ugly});
            arr[i]=minuglyNum;
            if(minuglyNum==i2ugly) i2++;
            if(minuglyNum==i3ugly) i3++;
            if(minuglyNum==i5ugly) i5++;
        }
        return arr[n];
    }
};
int main(){
    Solution sol;
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<n<<"th ugly number is : "<<sol.nthUglyNumber(n);
}