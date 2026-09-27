#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> st;
        
        for (char c : s) {
            if (c == ')') {
                string temp = "";
                // Pop characters until matching '(' is found
                while (!st.empty() && st.back() != '(') {
                    temp += st.back();
                    st.pop_back();
                }
                // Pop '('
                if (!st.empty()) {
                    st.pop_back();
                }
                // Push reversed characters back onto stack
                for (char ch : temp) {
                    st.push_back(ch);
                }
            } else {
                st.push_back(c);
            }
        }
        
        return string(st.begin(), st.end());
    }
};
