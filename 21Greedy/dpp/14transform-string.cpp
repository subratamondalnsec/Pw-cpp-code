#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int transform (string A, string B){
        int size_A=A.size(),size_B=B.size();
        if(size_A!=size_B) return -1;
        vector<int>f1(58,0);
        for(int i=0;i<size_A;i++){
            f1[A[i]-'A']++;
            f1[B[i]-'A']--;
        }
        for(int i=0;i<size_A;i++){
            if(f1[A[i]-'A']!=0) return -1;
        }
        int count=0;
        int i=size_A-1,j=size_B-1;
        while(i>=0 && j>=0){
            while(i>=0 && A[i]!=B[j]){
                i--;
                count++;
            }
            i--,j--;
        }
        return count;
    }
};
int main() {
    Solution solution;
	string A="GeeksForGeeks";
    string B="ForGeeksGeeks";
    cout<<"The conversion "<<A<<" to "<<B<<" can take place in operations : "<<solution.transform(A,B);
	return 0;
}