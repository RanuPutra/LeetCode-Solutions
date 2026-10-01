#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            // Push open brackets onto stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // Handle close brackets
            else {
                // Stack is empty when close bracket occurs -> invalid
                if (st.empty()) return false;
                
                char top = st.top();
                // Check if closing bracket matches top opening bracket
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    st.pop(); // Matching pair found, pop from stack
                } else {
                    return false; // Mismatched pair
                }
            }
        }
        
        // Valid only if all open brackets have been matched
        return st.empty();
    }
};
