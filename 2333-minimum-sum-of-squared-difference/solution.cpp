#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        
        // Find absolute differences and maximum difference
        int max_diff = 0;
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
            max_diff = max(max_diff, diff[i]);
        }
        
        // Frequency array storing count of elements with specific difference values
        vector<long long> count(max_diff + 1, 0);
        for (int i = 0; i < n; ++i) {
            count[diff[i]]++;
        }
        
        // Greedily reduce largest differences down to smaller values
        for (int v = max_diff; v > 0 && k > 0; --v) {
            if (count[v] == 0) continue;
            
            // Number of reductions needed to transition elements from v to v - 1
            long long take = min((long long)count[v], k);
            
            count[v] -= take;
            count[v - 1] += take;
            k -= take;
        }
        
        // Compute total sum of squared differences
        long long ans = 0;
        for (long long v = 1; v <= max_diff; ++v) {
            if (count[v] > 0) {
                ans += count[v] * v * v;
            }
        }
        
        return ans;
    }
};
