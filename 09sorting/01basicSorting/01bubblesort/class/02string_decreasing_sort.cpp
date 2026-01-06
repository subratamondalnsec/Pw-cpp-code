#include <bits/stdc++.h>
using namespace std;
int main(){
   string s="AZYZXBDJKX";
    string str="";
    for(int i=0;i<s.size();i++){
       if(s[i]>='X') str.push_back(s[i]);
    }
    for(int i=0;i<str.size();i++){
        cout<<str[i]<<" ";
    }
        cout<<endl;
   for(int i=0;i<str.size()-1;i++){
        for(int j=0;j<str.size()-1-i;j++){//traverse
            if(str[j]<str[j+1]){
                swap(str[j],str[j+1]);//
            }
        }
    }
    cout<<endl;
        for(int i=0;i<str.size();i++){
        cout<<str[i]<<" ";
    }
}