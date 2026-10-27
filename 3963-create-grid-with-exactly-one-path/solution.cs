using System;
using System.Collections.Generic;

public class Solution {
    public IList<string> CreateGrid(int m, int n) {
        string[] grid = new string[m];
        for (int i = 0; i < m; i++) {
            if (i == 0) {
                grid[i] = new string('.', n);
            } else {
                grid[i] = new string('#', n - 1) + ".";
            }
        }
        return grid;
    }
}
