#include<bits/stdc++.h>
using namespace std;

bool solve(int i,int a[],int n,int p,int target){
    if(i==n){
        if(target==p) return true;
        return false;
    }
    if(solve(i+1,a,n,p*a[i],target)) return true;
    if(solve(i+1,a,n,p,target)) return true;
    return false;
}
int main(){
    int n;
    cout<<"Enter the size o array : ";
    cin>>n;
    int target;
    cout<<"Enter the target : ";
    cin >> target;
    int a[n];
    cout<<"Enter the element : ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(solve(0,a,n,1,target)) cout<< "YES" ;
    else cout<<"NO";
}



/*
#include <iostream>
using namespace std;
    bool solve(int n, int target, int a[], int i, int product) {
        if (i == n) return product == target;
        bool ans = false;
        product *= a[i];
        ans = solve(n, target, a, i + 1, product);
        product /= a[i];
        ans = solve(n, target, a, i + 1, product);
        return ans;
    }
 int main() {
    int n, target;
    cin >> n >> target;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << (solve(n, target, a, 0, 1) ? "YES\n" : "NO\n");
    return 0;
 }
 
*/