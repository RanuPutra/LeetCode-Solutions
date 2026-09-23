#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }

        long long target = total_sum - x;

        // If target < 0, total sum of elements is less than x
        if (target < 0) return -1;

        // If target == 0, we must remove all elements
        if (target == 0) return nums.size();

        int max_len = -1;
        long long current_sum = 0;
        int left = 0;

        // Sliding window to find longest subarray with sum equal to target
        for (int right = 0; right < nums.size(); ++right) {
            current_sum += nums[right];

            // Shrink window if current_sum exceeds target
            while (current_sum > target && left <= right) {
                current_sum -= nums[left];
                left++;
            }

            // Record maximum length when current_sum matches target
            if (current_sum == target) {
                max_len = max(max_len, right - left + 1);
            }
        }

        // If max_len is still -1, no valid subarray exists
        return (max_len == -1) ? -1 : static_cast<int>(nums.size() - max_len);
    }
};
