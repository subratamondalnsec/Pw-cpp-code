#include <iostream>
#include <map>
#include <set>
using namespace std;
int main(){
    set<int>s;
    s.insert(1);
    s.insert(10);
    s.insert(7);
    s.insert(9);
    s.insert(5);
    s.insert(4);
    s.insert(8);
    s.insert(11);
    s.insert(2);
    s.insert(3);
    for(auto ele : s) cout<<ele<<"  ";//order set always element contain in sort order
    cout<<endl;
    map<int,int>mp;
    mp[2]=20;
    mp[3]=10;
    mp[1]=30;//order map always element contain in sort order in your key wise
    cout<<endl;
    for(auto ele : mp) cout<<ele.first<<"  "<<ele.second<<endl;
    map<string,int>sp;
    sp["subrata"]=20;
    sp["harsh"]=10;
    sp["raghav"]=30;
    for(auto ele : sp) cout<<ele.first<<"  "<<ele.second<<endl;

}