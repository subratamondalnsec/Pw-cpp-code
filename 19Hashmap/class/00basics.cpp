#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int>sp;

    //insertion

    pair<string,int>p1=make_pair("subrata",1);//1
    sp.insert(p1);

    pair<string,int>p2("babbar",2);//2
    sp.insert(p2);

    sp["raghav"]=3;//3

    //searching

    cout<<sp["subrata"]<<endl;
    cout<<sp.at("babbar")<<endl;
    
    //size
    cout<<sp.size();

    //checking present

    cout<<sp.count("subrata");
    cout<<sp.count("bro");

    //delete

    sp.erase("babbar");
    //traversal
    for(auto i : sp){
        cout<<i.first << "  "<<i.second<<endl;
    }

    unordered_map<string,int> :: iterator it=sp.begin();
    while(it !=sp.end()){
        cout<<it->first <<"  "<<it->second<<endl;
        it++;
    }
}