#include<bits/stdc++.h>
using namespace std;
class Vector{
public:
    int size;
    int capacity;
    int* arr;
    Vector(){
        size=0;
        capacity=1;
        arr=new int[1];
    }

    void add(int ele){
        if(size==capacity){
            capacity*=2;
            int* arr2 =new int[capacity];
            for(int i=0;i<size;i++){
                arr2[i]=arr[i];
            }
            arr=arr2;
        }
        arr[size++]=ele;
    }
    int get(int idx){
        if(size==0){
            cout<<"array is empty";
            return -1;
        }
        else if(idx>=size || idx<0){
            cout<<"invalid index";
            return -1;
        }
        else return arr[idx];
    }
    void remove(){
        if(size==0){
            cout<<"array is empty";
        }
        else size--;
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Vector v;
    v.add(10);
    v.add(15);
    v.add(18);
    v.add(19);
    v.add(20);
    v.print();
}