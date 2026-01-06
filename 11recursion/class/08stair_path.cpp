#include <bits/stdc++.h>
using namespace std;
// int stair(int n) {
//    int a = 0, b = 1;
//     for (int i = 0; i < n; ++i) {
//         int c = a + b;
//         a = b;
//         b = c;
//     }
//     return b;
// }

int stair(int n){
    if(n==2) return 2;
    if(n==1) return 1;
    return stair(n-1) +stair(n-2);
}
int main(){
    cout<<stair(5);
}

// #include <bits/stdc++.h> //t.c=s.c=O(1)
// using namespace std;

// int stair(int n) {
//     if (n == 0) return 0;
//     double sqrt5 = sqrt(5);
//     double phi = (1 + sqrt5) / 2;
//     return round(pow(phi, n + 1) / sqrt5);
// }

// int main() {
//     cout << stair(45);
// }
