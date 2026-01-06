#include <bits/stdc++.h>
using namespace std;
int main()
{
    // string str = "raghav is a maths teacher";
    // stringstream ss(str);
    // string temp;
    // string maxlexi="";
    // while (ss >> temp){ 
    //     maxlexi=max(maxlexi,temp);
    // }
    // cout<<maxlexi<<endl;
    /*method 2*/
    string str = "raghav is a maths teacher";
    string word="";
    string maxlexi="";
    for(int i=0;i<str.length();i++){
        if(str[i]==' '){
            maxlexi=max(maxlexi,word);
            word="";
        }
        else{
            word+=str[i];
        }
    }
    maxlexi=max(maxlexi,word);
    cout<<maxlexi;
}