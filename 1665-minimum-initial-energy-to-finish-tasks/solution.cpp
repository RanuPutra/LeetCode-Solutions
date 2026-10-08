#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort tasks in descending order of (minimum - actual)
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int res = 0; // Minimum initial energy required
        int cur = 0; // Current available energy

        for (const auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];

            // If current energy is less than minimum requirement, replenish difference
            if (cur < minimum) {
                res += (minimum - cur);
                cur = minimum;
            }

            // Spend energy to finish the task
            cur -= actual;
        }

        return res;
    }
};
