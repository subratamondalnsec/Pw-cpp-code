#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    cout<<"enter sorted order elements of the array"<<endl;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x=0;
    bool flag=false;
    for(int i=0;i<n;i++){
        if(a[i]!= x){
            cout<<x<<endl;
            flag=true;
            break;
        }
        else x++;
    }
    if(flag==false) cout<<x<<endl;
    return 0;
}