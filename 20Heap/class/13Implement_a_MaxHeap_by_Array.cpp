#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    int arr[50];
    int idx;
    MaxHeap(){
        idx=1;
    }
    int top(){
        return arr[1];
    }
    void push(int val){
        arr[idx]=val;
        int i=idx;
        idx++;
        //swapping till 1
        while(i!=1){
            int parent=i/2;
            if(arr[i]>arr[parent]) swap(arr[i],arr[parent]);
            else break;
            i=parent;
        }
    }
    void pop(){
        idx--;
        arr[1]=arr[idx];
        int i=1;
        while(true){
            int l=2*i;
            int r=2*i+1;
            if(l>idx-1)break;
            if(r>idx-1){
                if(arr[l]>arr[r] ){
                    if(arr[i]<arr[l]){
                        swap(arr[i],arr[l]);
                        i=l;
                    }
                    break;
                }
            }
            if(arr[l]>arr[r] ){
                if(arr[i]<arr[l]){
                    swap(arr[i],arr[l]);
                    i=l;
                }
                else break;
            }
            else{
                if(arr[i]<arr[r]){
                    swap(arr[i],arr[r]);
                    i=r;
                }
                else break;
            }
        }
    }
    int size(){
        return idx-1;
    }
    void display(){
        for(int i=1;i<idx;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};
int main(){
    MaxHeap pq;
    pq.push(10);
    pq.push(20);
    pq.push(3);
    pq.push(1);
    cout<<pq.top()<<endl;
    pq.push(15);
    pq.push(2);
    pq.push(0);
    pq.push(11);
    pq.display();
    cout<<pq.top()<<endl;
    pq.pop();
    pq.display();
    pq.pop();
    pq.display();
    pq.pop();
    pq.display();
    pq.pop();
    pq.display();
    pq.pop();
    pq.display();
    pq.pop();
    pq.display();
}