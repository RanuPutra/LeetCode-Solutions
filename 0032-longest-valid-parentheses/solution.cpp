#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Initial base boundary index
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i); // Store index of opening parenthesis
            } else {
                st.pop(); // Pop boundary marker or matching '(' index
                
                if (st.empty()) {
                    // Stack is empty: unmatched ')'. Set current index as new boundary.
                    st.push(i);
                } else {
                    // Calculate valid substring length from last boundary index
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }
};
