#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the student: ";
    cin>>n;
    int marks[n];
     cout<<"enter the marks: ";
    for(int i=0;i<=n-1;i++){
      cin>>marks[i];
    }
    cout<<endl<<"less the 35 marks roll number: ";
       for(int i=0;i<=n-1;i++){
        if(marks[i]<35) cout<<i<<" ";
      
    }
}