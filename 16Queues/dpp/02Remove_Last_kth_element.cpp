#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
    cout<<"Enter the size of queue : ";
	cin >> n;
    cout<<"Enter the remove element size of queue : ";
    cin >> k;
	queue<int> q;
    cout<<"Enter the element : ";
	for (int i = 0 ; i < n; i++) {
		int val;
		cin >> val;
		q.push(val);
	}
    for (int i = 0 ; i < n-k; i++) {
		q.push(q.front());
        q.pop();
	}
    for (int i = 0 ; i < k; i++) q.pop();
    for (int i = 0 ; i < n-k; i++) {
		cout<<q.front()<<"  ";
        q.push(q.front());
        q.pop();
	}
}