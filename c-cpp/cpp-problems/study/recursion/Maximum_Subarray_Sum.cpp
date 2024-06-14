#include <iostream>
#include <vector>
using namespace std;

int maxSubArraySum(const vector<int>& nums, int start, int end) {
    if (start == end)
        return nums[start];
    int mid = start + (end - start) / 2;
    int leftSum = maxSubArraySum(nums, start, mid);
    int rightSum = maxSubArraySum(nums, mid + 1, end);
    int leftMax = INT_MIN, rightMax = INT_MIN, sum = 0;
    for (int i = mid; i >= start; --i) {
        sum += nums[i];
        leftMax = max(leftMax, sum);
    }
    sum = 0;
    for (int i = mid + 1; i <= end; ++i) {
        sum += nums[i];
        rightMax = max(rightMax, sum);
    }
    return max(max(leftSum, rightSum), leftMax + rightMax);
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum: " << maxSubArraySum(nums, 0, nums.size() - 1) << endl;
    return 0;
}
