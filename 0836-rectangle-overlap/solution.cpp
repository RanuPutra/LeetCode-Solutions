#include <vector>

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Check if one rectangle is completely to the left, right, top, or bottom of the other.
        // If any of these are true, they do not overlap.
        bool left   = rec1[2] <= rec2[0];
        bool right  = rec1[0] >= rec2[2];
        bool bottom = rec1[3] <= rec2[1];
        bool top    = rec1[1] >= rec2[3];
        
        return !(left || right || bottom || top);
    }
};
