function createGrid(m: number, n: number): string[] {
    const grid: string[] = [];
    for (let i = 0; i < m; i++) {
        if (i === 0) {
            grid.push('.'.repeat(n));
        } else {
            grid.push('#'.repeat(n - 1) + '.');
        }
    }
    return grid;
}
