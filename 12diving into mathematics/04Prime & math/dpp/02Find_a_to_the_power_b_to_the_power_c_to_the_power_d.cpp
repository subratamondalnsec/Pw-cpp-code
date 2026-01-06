#include <bits/stdc++.h>
using namespace std;
long long pow(long long  a, long long  b, long long  m) {
	long long  ans = 1;
	while (b>0){
		if((b & 1)!=0)  ans = ((ans%m) * (a%m)) % m;
		a = ((a%m) *(a%m)) % m;
        b=b>>1;
	}
	return ans;
}
int main() {
	long long  a, b, c,d;
	cin >> a >> b >> c>> d;
	const long long  M = 1e9 + 7;
	cout << pow(a,pow(b, pow(c, d, M)), M);
}