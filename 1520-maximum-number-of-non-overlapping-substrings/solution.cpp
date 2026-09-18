#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> l(26, INT_MAX), r(26, -1);
        
        // Step 1: Record first and last index for each character
        for (int i = 0; i < n; ++i) {
            int charIdx = s[i] - 'a';
            l[charIdx] = min(l[charIdx], i);
            r[charIdx] = max(r[charIdx], i);
        }
        
        // Step 2: Expand interval boundaries to satisfy full character occurrence condition
        // Valid intervals are stored as {right_index, left_index}
        vector<pair<int, int>> validIntervals;
        
        for (int i = 0; i < 26; ++i) {
            if (l[i] == INT_MAX) continue; // Character does not exist in string
            
            int left = l[i];
            int right = r[i];
            bool isValid = true;
            
            for (int j = left; j <= right; ++j) {
                int currChar = s[j] - 'a';
                // If a character inside the range starts before 'left',
                // this interval cannot start at 'left'
                if (l[currChar] < left) {
                    isValid = false;
                    break;
                }
                right = max(right, r[currChar]);
            }
            
            if (isValid) {
                // Store as {right, left} for easy sorting by 'right' index
                validIntervals.push_back({right, left});
            }
        }
        
        // Step 3: Sort valid intervals by end position (right index)
        sort(validIntervals.begin(), validIntervals.end());
        
        // Step 4: Greedily select non-overlapping intervals
        vector<string> result;
        int lastRight = -1;
        
        for (const auto& interval : validIntervals) {
            int right = interval.first;
            int left = interval.second;
            
            // Pick interval if it does not overlap with previously selected interval
            if (left > lastRight) {
                result.push_back(s.substr(left, right - left + 1));
                lastRight = right;
            }
        }
        
        return result;
    }
};
