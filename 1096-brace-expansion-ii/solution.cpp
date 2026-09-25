#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stack>
#include <algorithm>
#include <cctype>

using namespace std;

class Solution {
public:
    // Helper function to compute Cartesian Product of two sets (Concatenation)
    set<string> multiply(const set<string>& set1, const set<string>& set2) {
        set<string> result;
        for (const string& s1 : set1) {
            for (const string& s2 : set2) {
                result.insert(s1 + s2);
            }
        }
        return result;
    }

    // Helper function to compute Set Union
    set<string> unite(const set<string>& set1, const set<string>& set2) {
        set<string> result = set1;
        result.insert(set2.begin(), set2.end());
        return result;
    }

    vector<string> braceExpansionII(string expression) {
        stack<char> ops;
        stack<set<string>> operands;

        auto evaluate = [&]() {
            char op = ops.top();
            ops.pop();

            set<string> right = operands.top(); operands.pop();
            set<string> left = operands.top(); operands.pop();

            if (op == '*') {
                operands.push(multiply(left, right));
            } else if (op == '+') {
                operands.push(unite(left, right));
            }
        };

        for (int i = 0; i < expression.length(); ++i) {
            char c = expression[i];

            if (c == '{') {
                // If previous char is a letter or '}', add implicit multiplication operator
                if (i > 0 && (isalpha(expression[i - 1]) || expression[i - 1] == '}')) {
                    while (!ops.empty() && ops.top() == '*') {
                        evaluate();
                    }
                    ops.push('*');
                }
                ops.push('{');
            } else if (isalpha(c)) {
                // If previous char is a letter or '}', add implicit multiplication operator
                if (i > 0 && (isalpha(expression[i - 1]) || expression[i - 1] == '}')) {
                    while (!ops.empty() && ops.top() == '*') {
                        evaluate();
                    }
                    ops.push('*');
                }
                operands.push({string(1, c)});
            } else if (c == ',') {
                while (!ops.empty() && ops.top() != '{') {
                    evaluate();
                }
                ops.push('+'); // '+' represents union (comma)
            } else if (c == '}') {
                while (!ops.empty() && ops.top() != '{') {
                    evaluate();
                }
                ops.pop(); // Pop '{'
            }
        }

        while (!ops.empty()) {
            evaluate();
        }

        // Convert set to sorted vector
        set<string> finalSet = operands.top();
        return vector<string>(finalSet.begin(), finalSet.end());
    }
};
