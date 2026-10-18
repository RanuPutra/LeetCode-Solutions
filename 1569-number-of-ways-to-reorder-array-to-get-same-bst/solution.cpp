#include <vector>

using namespace std;

class Solution {
private:
    const int MOD = 1e9 + 7;
    vector<vector<long long>> comb;

    long long dfs(const vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        int root = nums[0];

        // Partition remaining elements into left and right subtrees
        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long left_ways = dfs(left);
        long long right_ways = dfs(right);

        int l_size = left.size();
        int r_size = right.size();

        // C(L + R, L) * ways(left) * ways(right) % MOD
        long long total = comb[l_size + r_size][l_size];
        total = (total * left_ways) % MOD;
        total = (total * right_ways) % MOD;

        return total;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        // Precompute combinations using Pascal's Triangle
        comb.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        // Subtract 1 because the initial array itself does not count as a reordering
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};
