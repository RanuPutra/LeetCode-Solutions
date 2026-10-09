#include <string>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int needed_closing = 0;

        for (char c : s) {
            if (c == '(') {
                // If odd number of ')' needed, insert one ')' to complete pair
                if (needed_closing % 2 == 1) {
                    ans++;
                    needed_closing--;
                }
                // Each '(' requires two ')'
                needed_closing += 2;
            } else { // c == ')'
                needed_closing--;
                // If excess ')', insert one '('
                if (needed_closing < 0) {
                    ans++;              // Insert one '('
                    needed_closing = 1; // That '(' still needs one more ')'
                }
            }
        }

        // Add remaining needed ')'
        return ans + needed_closing;
    }
};
