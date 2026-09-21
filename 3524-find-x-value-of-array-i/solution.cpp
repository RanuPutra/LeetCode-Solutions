#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        
        // dp[rem] stores the count of subarrays ending at the previous position
        // whose product modulo k equals rem.
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> next_dp(k, 0);
            int mod_val = num % k;

            // 1. A new subarray starting at the current element
            next_dp[mod_val]++;

            // 2. Extend existing subarrays ending at the previous element
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int new_rem = (r * mod_val) % k;
                    next_dp[new_rem] += dp[r];
                }
            }

            // Accumulate counts for the answer
            for (int r = 0; r < k; ++r) {
                result[r] += next_dp[r];
            }

            dp = move(next_dp);
        }

        return result;
    }
};
