#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;//declactin
        v.push_back(4);//added the element
        v.push_back(6);//v[1]=6->it error
        v.push_back(7);
        v.push_back(8); 
        v.push_back(9); 
        cout<<v[0]<<" ";//print the value
        cout<<v[1]<<" ";
        cout<<v[2]<<" ";
        cout<<v[3]<<" ";
        cout<<v[4]<<" "<<endl;
        cout<<v.size()<<endl;//joto gulo element ache
        cout<<v.capacity()<<endl;//joto gulo box ache
        v.pop_back();//recently added elment delete the element;
        cout<<v.size()<<endl;
        cout<<v.capacity()<<endl;
        for(int i=0;i<v.size();i++){//looping print thevalue
            cout<<v[i]<<" "; 
        }
        cout<<endl; 
        vector<int>vec;
           for(int j=0;j<5;j++){//vector intput
            int x;
            cin>>x;
            vec.push_back(x);
           }
           for(int i=0;i<vec.size();i++){//looping print thevalue
            cout<<vec[i]<<" "; 
           }
           cout<<endl; 
           vector<int>ve(5);//intialzation it all element is 0
            for(int i=0;i<ve.size();i++){//looping print thevalue
            cout<<ve[i]<<" "; 
            }
            cout<<endl; 
            vector<int>vect(5,7);//intialzation it all element is 7
            for(int i=0;i<vect.size();i++){//looping print thevalue
            cout<<vect[i]<<" "; 
            }
            cout<<endl; 
    }