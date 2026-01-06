#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int bloom(int n, vector<int>& b) {
    unordered_map<int, int> freq;
    for (int val : b) {
        freq[val]++;
    }

    int cnt = 0;
    vector<int> trmd(b);

    for (int i = 0; i < n; ++i) {
        int less = 0, more = 0;
        for (int j = 0; j < n; ++j) {
            if (b[j] < b[i]) less++;
            else if (b[j] > b[i]) more++;
        }
        if (less == more && freq[b[i]] <= 2) {
            cnt++;
            trmd[i]=b[i];
            continue; 
        } else {
            trmd[i] = 0; 
        }
    }

    if (cnt == 0) {
        int sum = 0;
        for (int val : b) sum += val;
        return sum;
    }
    else{
        int tsum = 0;
        for (int val : trmd) tsum += val;
        return tsum;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int result = bloom(n, b);
    cout << result << endl;
    return 0;
}
