#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid;
        grid.reserve(m);
        for (int i = 0; i < m; ++i) {
            if (i == 0) {
                grid.emplace_back(n, '.');
            } else {
                grid.push_back(string(n - 1, '#') + '.');
            }
        }
        return grid;
    }
};
