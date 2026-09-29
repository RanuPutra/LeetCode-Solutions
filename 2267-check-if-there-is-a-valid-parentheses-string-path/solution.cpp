#include <vector>
#include <tuple>
#include <utility>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int pathLen = m + n - 1;

        // Condition 1: Path length must be even for balanced parentheses
        if (pathLen % 2 != 0) return false;
        
        // Condition 2: Start must be '(' and end must be ')'
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        int maxBal = pathLen / 2;
        
        // Visited array: visited[r][c][bal]
        // Prevents re-evaluating cell (r, c) with same balance value
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(maxBal + 1, false)));

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}}; // Right and Down
        vector<tuple<int, int, int>> q;
        
        // Initialize starting cell (0, 0)
        q.push_back({0, 0, 1});
        visited[0][0][1] = true;

        int head = 0;
        while (head < q.size()) {
            auto [r, c, bal] = q[head++];

            // If destination cell is reached
            if (r == m - 1 && c == n - 1) {
                if (bal == 0) return true;
                continue;
            }

            for (auto& dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr < m && nc < n) {
                    int nextBal = bal + (grid[nr][nc] == '(' ? 1 : -1);

                    // Valid prefix path if balance >= 0 and <= maxBal
                    if (nextBal >= 0 && nextBal <= maxBal) {
                        if (!visited[nr][nc][nextBal]) {
                            visited[nr][nc][nextBal] = true;
                            q.push_back({nr, nc, nextBal});
                        }
                    }
                }
            }
        }

        return false;
    }
};
