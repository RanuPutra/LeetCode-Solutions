#include <string>

using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int totalSum = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Reversed alphabet position: 'a' = 26, 'b' = 25, ..., 'z' = 1
            int reversedAlphabetPos = 26 - (s[i] - 'a');
            
            // Character position in string (1-indexed)
            int stringPos = i + 1;
            
            // Accumulate product into total
            totalSum += reversedAlphabetPos * stringPos;
        }
        
        return totalSum;
    }
};
