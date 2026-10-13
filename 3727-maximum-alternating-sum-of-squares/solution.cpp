#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares(n);
        
        for (int i = 0; i < n; ++i) {
            squares[i] = 1LL * nums[i] * nums[i];
        }
        
        sort(squares.begin(), squares.end());
        
        int neg_count = n / 2;
        long long total = 0;
        
        // Subtract the n / 2 smallest squares
        for (int i = 0; i < neg_count; ++i) {
            total -= squares[i];
        }
        // Add the remaining largest squares
        for (int i = neg_count; i < n; ++i) {
            total += squares[i];
        }
        
        return total;
    }
};
