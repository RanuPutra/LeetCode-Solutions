#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0;
        int maxOpen = 0;

        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else { // c == '*'
                minOpen--; // If '*' is treated as ')'
                maxOpen++; // If '*' is treated as '('
            }

            // Excess right parentheses: string cannot be valid
            if (maxOpen < 0) {
                return false;
            }

            // minOpen cannot drop below 0
            if (minOpen < 0) {
                minOpen = 0;
            }
        }

        // Valid if 0 open parentheses is a reachable state
        return minOpen == 0;
    }
};
