#include <bits/stdc++.h>
using namespace std;
/* leet 60*/
class solution{
    public:
    string helper(string str,int k,string ans){
       int n=str.length();
       if(n==0) return ans;
        int fact=1;
        for(int i=2;i<=n-1;i++){
            fact*=i;
        }
        int idx=k/fact;
        if(k%fact==0) idx--;
        char ch=str[idx];
        string left=str.substr(0,idx);
         string right=str.substr(idx+1);
         int q=1;
         if(k%fact==0) q=fact;
         else q=k%fact;

         return helper(left+right,q,ans+ch);
    }
      string getPermutation(int n,int k){
        //123
        //123 132 213 231 312 321
         string str ="";
         for(int i=1;i<=n;i++){
            str+=to_string(i);
         }
         string ans="";
         return  helper(str,k,"");
      }
};
int main() {
    solution solution;
    int n, k;

    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    string result = solution.getPermutation(n, k);
    cout << "The " << k << "-th permutation sequence of numbers 1 to " << n << " is: " << result << endl;

    return 0;
}
