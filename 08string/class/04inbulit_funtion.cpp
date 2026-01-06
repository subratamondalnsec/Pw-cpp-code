#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "subrata";
     cout<<s.size()<<endl;
      cout<<s.length()<<endl;
      s.push_back('m');
       cout<<s<<endl;
       s.pop_back();
       cout<<s<<endl;
       string t = "Mondal";
       cout<<(s+t)<<endl;//+ operator
       reverse(s.begin(),s.end());
        cout<<s<<endl;
        reverse(t.begin(),t.end()-1);
         cout<<t<<endl;
         string p = "ragavh";
         reverse(p.begin(),p.begin()+5);
         cout<<p<<endl;
          cout<<"--substring--"<<endl;
          string q="abcdefgh";
          int n=q.length();
          cout<<q.substr(1)<<endl;//index
          cout<<q.substr(3)<<endl;
          cout<<q.substr(5)<<endl;
          cout<<q.substr(2,2)<<endl;//(index,length)
          cout<<q.substr(1,3)<<endl;
          cout<<q.substr(1,4)<<endl;
          cout<<q.substr(2,3)<<endl ;  
    }