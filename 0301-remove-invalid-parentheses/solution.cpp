#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
private:
    // Helper function to check if a parentheses string is valid
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false; // Excess closing parenthesis
            }
        }
        return count == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if (s.empty()) return result;

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            if (isValid(current)) {
                result.push_back(current);
                found = true; // Mark valid solution found at current BFS level
            }

            // Stop generating child strings for deeper levels once valid solution found
            if (found) continue;

            // Generate all candidate strings by removing 1 parenthesis character
            for (int i = 0; i < current.length(); i++) {
                if (current[i] != '(' && current[i] != ')') continue;

                string nextStr = current.substr(0, i) + current.substr(i + 1);

                if (visited.find(nextStr) == visited.end()) {
                    visited.insert(nextStr);
                    q.push(nextStr);
                }
            }
        }

        return result;
    }
};
