#include <bits/stdc++.h>
using namespace std;
// class Solution {//bekar method
// public:
//     string addStrings(string num1, string num2) {
//         string big="";
//         string small="";
//         if(num1.length()>num2.length()){
//             big=num1;
//             small=num2;
//         }
//         else if(num1.length()<num2.length()){
//             big=num2;
//             small=num1;
//         }
//         else {
//             for(int i =0;i<num1.length();i++){
//                 int x=num1[i]-'0';
//                 int y=num2[i]-'0';
//                 if(x>y){
//                     big=num1;
//                     small=num2;
//                 }
//                 else if(x<y){
//                     big=num1;
//                     small=num2;
//                 }
//                 else continue;
//             }
//         }
//         if(big==""||small=="") {
//             big=num1;
//             small=num2;
//         }
//         string res="";
//         int carry=0;
//         int i=big.length()-1;
//         int j= small.length()-1;
//         while(i>=0&&j>=0){
//             int x= big[i]-'0';
//             int y=small[j]-'0';
//             int z=(x+y)%10;
//             z+=carry;
//             if(z==10) res+=to_string(0);
//             else res+=to_string(z);
//             if(z==10) carry=1;
//             else  carry=(x+y)/10;
//             i--;
//             j--;
//         }
//         while(i>=0){
//             int x=big[i]-'0';
//             int  z=(x)%10;
//              z+=carry;
//             if(z==10) res+=to_string(0);
//             else res+=to_string(z);
//              if(z==10) carry=1;
//             else  carry=(x)/10;
//             i--;
//         }
//         if(carry>0) res+=to_string(carry);
//         reverse(res.begin(),res.end());
//         return res;
//     }
// };


class Solution {
public:
    string addStrings(string num1, string num2) {
       int carry = 0;
        string res = "";
        // Start from the last digit of both numbers
        int i = num1.size() - 1;//3
        int j = num2.size() - 1;//2
        // Process both strings from the end to the beginning
        while (i >= 0 || j >= 0 || carry > 0) {
            int x = (i >= 0) ? num1[i] - '0' : 0;
            int y = (j >= 0) ? num2[j] - '0' : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            res += to_string(sum % 10);
            i--;
            j--;
        }
        // The result is reversed since we added digits from the least significant side
        reverse(res.begin(), res.end());
        return res;
    }
};
int main() {
    Solution solution;
    string num1 = "1236";
    string num2 = "987";
    string result = solution.addStrings(num1, num2);
    cout << "Sum: " << result << endl;
    return 0;
}