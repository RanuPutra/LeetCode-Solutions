#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int opened = 0;
        
        for (char c : s) {
            if (c == '(') {
                // If opened > 0, c is not the outermost '('
                if (opened > 0) {
                    res += c;
                }
                opened++;
            } else { // c == ')'
                opened--;
                // If opened > 0 after decrement, c is not the outermost ')'
                if (opened > 0) {
                    res += c;
                }
            }
        }
        
        return res;
    }
};
