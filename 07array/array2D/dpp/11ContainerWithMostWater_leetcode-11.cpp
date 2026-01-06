#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n - 1;
        int maxarea = 0;
        while (i < j) {
            int length = j - i;
            int width = min(height[i], height[j]);
            int area = length * width;
            maxarea = max(maxarea, area);
            if (height[i] < height[j]) i++;
            else j--;
        }
        return maxarea;
    }
};

int main() {
    Solution sol;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max Area: " << sol.maxArea(height) << endl;
    return 0;
}


