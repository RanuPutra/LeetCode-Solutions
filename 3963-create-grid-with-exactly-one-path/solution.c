#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** createGrid(int m, int n, int* returnSize) {
    *returnSize = m;
    char** grid = (char**)malloc(m * sizeof(char*));
    for (int i = 0; i < m; ++i) {
        grid[i] = (char*)malloc((n + 1) * sizeof(char));
        if (i == 0) {
            memset(grid[i], '.', n);
        } else {
            memset(grid[i], '#', n - 1);
            grid[i][n - 1] = '.';
        }
        grid[i][n] = '\0';
    }
    return grid;
}
