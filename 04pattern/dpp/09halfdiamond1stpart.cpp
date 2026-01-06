#include <bits/stdc++.h>
using namespace std;
int main() {
 int n;
 cin >> n;
 // Printing upper triangle
    for(int i = 1; i <= 2*n-1; ++i) {
       if(i<=n){ 
            for(int k=n-i;k>=1;k--){
                cout<<"  ";
            }
            for(int j = 1; j <= i; ++j) {
            cout << "* ";
        }
       }
       else{
            for(int k=i-n;k>=1;k--){
                cout<<"  ";
            }
            for(int j = i; j <=2*n-1 ; ++j) {
                cout << "* ";
            }
       }
        cout << endl;
    }
}