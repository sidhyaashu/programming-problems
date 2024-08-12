#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int>& nums, int sum, int index) {
    if (sum == 0)
        return true;
    if (index == nums.size() || sum < 0)
        return false;
    return subsetSum(nums, sum - nums[index], index + 1) || subsetSum(nums, sum, index + 1);
}

int main() {
    vector<int> nums = {2, 3, 7, 8, 10};
    int targetSum = 11;
    if (subsetSum(nums, targetSum, 0))
        cout << "Subset with sum " << targetSum << " exists." << endl;
    else
        cout << "No subset with sum " << targetSum << " exists." << endl;
    return 0;
}
