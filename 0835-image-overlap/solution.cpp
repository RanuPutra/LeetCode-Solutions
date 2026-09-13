#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> v1;
        vector<pair<int, int>> v2;
        
        // Extract the coordinates of all 1s in both images
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) v1.push_back({i, j});
                if (img2[i][j] == 1) v2.push_back({i, j});
            }
        }
        
        int max_overlap = 0;
        // The maximum possible translation is n-1 in any direction.
        // Offsetting by n ensures all indices are non-negative.
        vector<vector<int>> count(2 * n + 1, vector<int>(2 * n + 1, 0));
        
        // Calculate the translation vector for each pair of 1s
        for (auto& p1 : v1) {
            for (auto& p2 : v2) {
                int shift_r = p2.first - p1.first + n;
                int shift_c = p2.second - p1.second + n;
                count[shift_r][shift_c]++;
                
                if (count[shift_r][shift_c] > max_overlap) {
                    max_overlap = count[shift_r][shift_c];
                }
            }
        }
        
        return max_overlap;
    }
};
