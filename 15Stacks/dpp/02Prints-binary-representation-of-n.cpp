#include <bits/stdc++.h>
using namespace std;
void Binary(int n){
    stack<int> s;
    while (n > 0){
    s.push(n%2);
    n = n/2;
 }
    while (!s.empty()){
        cout<<s.top();
        s.pop();
    }
}
int main(){ 
    int n;
    cout<<"Enter the Number : ";
    cin>>n;
    Binary(n);
}
