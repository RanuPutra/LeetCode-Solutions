/**
 * @param {number} m
 * @param {number} n
 * @return {string[]}
 */
var createGrid = function(m, n) {
    const grid = [];
    for (let i = 0; i < m; i++) {
        if (i === 0) {
            grid.push('.'.repeat(n));
        } else {
            grid.push('#'.repeat(n - 1) + '.');
        }
    }
    return grid;
};
