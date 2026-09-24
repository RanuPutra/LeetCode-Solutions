#include <vector>

using namespace std;

class Solution {
private:
    // Helper function to calculate sum of digits
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (getDigitSum(nums[i]) == i) {
                return i; // Iterating from 0 upwards ensures first match is smallest
            }
        }
        return -1; // If no index satisfies condition
    }
};
