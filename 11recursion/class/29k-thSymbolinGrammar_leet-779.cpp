/*leet -779*/
#include <bits/stdc++.h>
using namespace std;
    int kthGrammar(int n,int k){
        if(n==1) return 0;
        if(k%2==0){//flip , even ,k/2
            int prevans =kthGrammar(n-1,k/2);
            if(prevans==0) return 1;
            else return 0;
        }
        else{//same , odd ,k/2+1
            int prevans=kthGrammar(n-1,k/2+1);
            return prevans;
        }
    }
int main() {
    int n, k;

    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    int result =kthGrammar(n, k);
    cout << "The " << k << "-th symbol in the " << n << "-th row of the grammar sequence is: " << result << endl;

    return 0;
}