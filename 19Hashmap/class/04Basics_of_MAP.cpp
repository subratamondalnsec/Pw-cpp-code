#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    pair<int,int>p;
    pair<string,int>p1;
    pair<int,int>p2;
    pair<string,int>p3;
    pair<int,int>p4;
    pair<string,int>p5;
    unordered_map<int,int>mp;
    unordered_map<string,int>sp;
    p.first=14;
    p.second=15;
    p1.first="subrata";
    p1.second=1;
    mp.insert(p);
    sp.insert(p1);
    p2.first=19;
    p2.second=20;
    p3.first="raghav";
    p3.second=2;
    mp.insert(p2);
    sp.insert(p3);
    p4.first=32;
    p4.second=1;
    p5.first="sanket";
    p5.second=5;
    mp.insert(p4);
    sp.insert(p5);
    for(pair<int,int> ele : mp){
        cout<<ele.first<<"  "<<ele.second<<endl;
    }
    for(auto ele : sp){
        cout<<ele.first<<"  "<<ele.second<<endl;
    }

/* anather mathod to insert in map */

    unordered_map<int,int>m;//first is key,second is value
    unordered_map<string,int>s;
    m[3]=15;
    m[5]=25;
    m[1]=58;
    s["subrata"]=1;
    s["sanket"]=5;
    s["raghav"]=2;
    for(pair<int,int> ele : m){
        cout<<ele.first<<"  "<<ele.second<<endl;
    }
    for(auto ele : s){
        cout<<ele.first<<"  "<<ele.second<<endl;
    }
    m.erase(3);
    s.erase("subrata");
    for(pair<int,int> ele : m){
        cout<<ele.first<<"  "<<ele.second<<endl;
    }
    for(auto ele : s){
        cout<<ele.first<<"  "<<ele.second<<endl;
    }
    cout<<m.size()<<endl;
    cout<<s.size()<<endl;
    if(s.find("raghav")!= s.end()) cout<<"present\n";
    if(m.find(5)!= m.end()) cout<<"present\n";
}