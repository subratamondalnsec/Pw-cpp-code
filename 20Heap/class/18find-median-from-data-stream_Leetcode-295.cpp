#include <iostream>
#include <queue>
using namespace std;
class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int,vector<int> , greater<int> >right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {//O(log(n))
        if(left.size()==0 || left.top()>num) left.push(num);//log(n)
        else right.push(num);//log(n)
        if(left.size()>right.size()+1) {
            right.push(left.top());//log(n)
            left.pop();//log(n)
        }
        if(left.size()+1<right.size()){
            left.push(right.top());//log(n)
            right.pop();//log(n)
        }
    }
    
    double findMedian() {//O(1)
        if(left.size()==right.size()) return(left.top()+right.top())/2.0;
        else{
            if(left.size()>right.size()) return left.top();
            else return right.top();
        }
    }
};

int main() {
    MedianFinder mf;
    
    mf.addNum(1);
    cout << "Median: " << mf.findMedian() << endl; // Output: 1

    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl; // Output: 1.5

    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2

    mf.addNum(4);
    cout << "Median: " << mf.findMedian() << endl; // Output: 2.5

    mf.addNum(5);
    cout << "Median: " << mf.findMedian() << endl; // Output: 3

    return 0;
}