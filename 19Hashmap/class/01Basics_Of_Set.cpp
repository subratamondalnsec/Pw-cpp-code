#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    cout<<s.size()<<endl;//set store unique element
    for(int ele:s){//display
        cout<<ele<<"  ";
    }
    cout<<endl;
    s.erase(4);//delete 4
    for(int ele:s){//display
        cout<<ele<<"  ";
    }
    cout<<endl;
    int target=6;
    if(s.find(target)!=s.end()) cout<<"target exist"<<endl;
    else cout<<"target not exist"<<endl;
}