#include <bits/stdc++.h>
using namespace std;
bool isPossible(int N, int A[], int X, int Y, int Z){
    // Declaring a set
    set<int> S({0});
    int curr = 0;
    for (int i = 0; i < N; i++){
        curr += A[i];
        S.insert(curr);
    }
    for (auto it : S){
        if (S.find(it + X) != S.end() && S.find(it + X + Y) != S.end() && S.find(it + X + Y + Z) != S.end())return true;
    }
    return false;
}
int main(){
    int N = 10, X = 5, Y = 7, Z = 5;
    int A[] = {1, 3, 2, 2, 2, 3, 1, 4, 3, 2};
    int answer = isPossible(N, A, X, Y, Z);
    if (answer == true) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}