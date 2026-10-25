function closedIsland(grid: number[][]): number {
    const m: number = grid.length;
    const n: number = grid[0].length;

    function dfs(r: number, c: number): void {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] !== 0) {
            return;
        }
        grid[r][c] = 1;
        dfs(r + 1, c);
        dfs(r - 1, c);
        dfs(r, c + 1);
        dfs(r, c - 1);
    }

    // Flood fill lands connected to the boundary
    for (let i = 0; i < m; i++) {
        if (grid[i][0] === 0) dfs(i, 0);
        if (grid[i][n - 1] === 0) dfs(i, n - 1);
    }
    for (let j = 0; j < n; j++) {
        if (grid[0][j] === 0) dfs(0, j);
        if (grid[m - 1][j] === 0) dfs(m - 1, j);
    }

    let closedIslands: number = 0;
    // Count remaining closed islands
    for (let i = 1; i < m - 1; i++) {
        for (let j = 1; j < n - 1; j++) {
            if (grid[i][j] === 0) {
                closedIslands++;
                dfs(i, j);
            }
        }
    }

    return closedIslands;
}
