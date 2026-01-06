#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={1,3,2,1,3,1};
    sort(v.begin(),v.end());//1 1 1 2 3 3
    int maxfrequency=1;
    int currfrequency=1;
    int n=v.size();
    for(int i=1;i<n;i++){
        if(v[i]==v[i-1]){
            currfrequency++;
        }
        else{
            if(maxfrequency<currfrequency){
                maxfrequency=currfrequency;
            }
            currfrequency=1;
        }
    }
    if(maxfrequency<currfrequency){
        maxfrequency=currfrequency;
    }
    cout<<"minmum operation requiered of sort the array : "<<(n-maxfrequency);
}