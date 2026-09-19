#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find x-coordinate on the rectangle closest to the circle's center
        int closestX = max(x1, min(xCenter, x2));
        
        // Find y-coordinate on the rectangle closest to the circle's center
        int closestY = max(y1, min(yCenter, y2));
        
        // Compute distance vector from circle center to closest point
        int distX = xCenter - closestX;
        int distY = yCenter - closestY;
        
        // Check if squared distance is within radius squared
        return (distX * distX + distY * distY) <= (radius * radius);
    }
};
