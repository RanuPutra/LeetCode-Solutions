#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void backtrack(vector<string>& result, string current, int open, int close, int max) {
        // Base case: string length reaches n * 2
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }

        // Add open bracket '(' if count is less than n
        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }

        // Add close bracket ')' if count is less than open count
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};
