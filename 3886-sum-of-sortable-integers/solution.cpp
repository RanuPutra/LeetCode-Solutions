#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        
        auto is_sortable = [&](int k) -> bool {
            int prev_max = -1;
            
            for (int i = 0; i < n; i += k) {
                // Check if block nums[i ... i + k - 1] can be cyclically rotated to sorted order
                int drop_count = 0;
                int min_val = nums[i];
                int max_val = nums[i];
                
                for (int j = 0; j < k; ++j) {
                    min_val = min(min_val, nums[i + j]);
                    max_val = max(max_val, nums[i + j]);
                    
                    int cur = nums[i + j];
                    int next = nums[i + (j + 1) % k];
                    if (cur > next) {
                        drop_count++;
                    }
                }
                
                // If more than 1 cyclic descent occurs, the block cannot be sorted
                if (drop_count > 1) {
                    return false;
                }
                
                // Verify that minimum of current block is >= maximum of previous block
                if (prev_max != -1 && min_val < prev_max) {
                    return false;
                }
                
                prev_max = max_val;
            }
            
            return true;
        };
        
        int total_sum = 0;
        
        // Check all divisors k of n
        for (int k = 1; k * k <= n; ++k) {
            if (n % k == 0) {
                if (is_sortable(k)) {
                    total_sum += k;
                }
                if (k * k != n) {
                    int k2 = n / k;
                    if (is_sortable(k2)) {
                        total_sum += k2;
                    }
                }
            }
        }
        
        return total_sum;
    }
};
