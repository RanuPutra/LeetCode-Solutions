#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            unordered_set<int> distinctElements;
            for (int j = i; j < n; ++j) {
                // Insert element into set
                distinctElements.insert(nums[j]);
                
                // Size of set represents distinct count in subarray nums[i..j]
                int count = distinctElements.size();
                
                // Add square of distinct count to total
                totalSum += count * count;
            }
        }
        
        return totalSum;
    }
};
