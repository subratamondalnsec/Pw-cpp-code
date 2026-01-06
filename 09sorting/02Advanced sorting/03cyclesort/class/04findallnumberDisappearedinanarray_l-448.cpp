#include <bits/stdc++.h>
using namespace std;
class solution{
public:
  vector<int> findDisappearedNumbers(vector<int> &nums){
    int n = nums.size();
    int i = 0;
    while (i < n){
      int correctIdx = nums[i] - 1;
      if (nums[correctIdx] == nums[i] || correctIdx == i) i++;
      else swap(nums[i], nums[correctIdx]);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++){
      if (nums[i] != i + 1) ans.push_back(i + 1);
    }
    return ans;
  }
};

int main()
{
  // Sample input
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

  // Create an instance of the Solution class
  solution solution;

  // Find the disappeared numbers
  vector<int> disappearedNumbers = solution.findDisappearedNumbers(nums);

  // Print the result
  cout << "The disappeared numbers are: ";
  for (int num : disappearedNumbers)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}