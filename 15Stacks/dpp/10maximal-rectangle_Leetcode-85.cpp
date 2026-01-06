#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();//Next Smallest index
        int nsi[n];
        stack<int> st;
        nsi [n-1] = n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--) {
            while(st.size()>0 && arr[st.top()]>=arr[i]) st.pop();
            if(st.size()==0) nsi[i] = n;
            else nsi[i] = st.top();
            st.push(i);
        }

        int psi [n];//previous Smallest index
        stack<int> gt;
        psi [0] = -1;
        gt.push(0);
        for(int i=1;i<n;i++) {
            while(gt.size()>0 && arr[gt.top()]>=arr[i]) gt.pop();
            if(gt.size()==0) psi[i] = -1;
            else psi [i] = gt.top();
            gt.push(i);
        }

        int maxArea = 0;
        for(int i=0;i<n;i++) {
            int height = arr[i];
            int breadth = nsi[i]- psi [i] - 1;
            int area = height*breadth;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;
        vector<int> row(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1')row[j] += 1;
                else row[j] = 0;
            }
            maxArea = max(maxArea , largestRectangleArea(row));
        }
        return maxArea;
    }
};

int main() {
    Solution sol;
    
    // Example matrix
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    
    int result = sol.maximalRectangle(matrix);
    cout << "The maximal rectangle area is: " << result << endl;

    return 0;
}