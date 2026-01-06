#include<bits/stdc++.h>
using namespace std;
int n;
void palindromes(int i,string& curr){
    if(i<= (n + 1) / 2){
        for(char j ='0';j<='9';j++){
           curr.push_back(j);
           palindromes(i+1,curr);
           curr.pop_back();
        }
    }
    else{
        string temp=curr;
        if(n%2==1) temp.pop_back();
        reverse(temp.begin(),temp.end());
        cout<<curr+temp<<" , ";
    }
}
int main(){
    cout<<"Enter the number : ";
    cin>>n;
    string curr="";
    palindromes(1,curr);
}