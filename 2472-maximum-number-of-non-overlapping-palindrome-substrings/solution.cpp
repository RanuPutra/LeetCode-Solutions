#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to check if s[left...right] is a palindrome
    bool isPal(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        // dp[i] stores max non-overlapping palindromes from prefix s[0 ... i-1]
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            // Option 1: Current character is not part of a selected palindrome
            dp[i] = dp[i - 1];
            
            // Option 2: Select palindrome of exact length k ending at index i - 1
            if (i >= k && isPal(s, i - k, i - 1)) {
                dp[i] = max(dp[i], dp[i - k] + 1);
            }
            
            // Option 3: Select palindrome of exact length k + 1 ending at index i - 1
            if (i >= k + 1 && isPal(s, i - k - 1, i - 1)) {
                dp[i] = max(dp[i], dp[i - k - 1] + 1);
            }
        }
        
        return dp[n];
    }
};
