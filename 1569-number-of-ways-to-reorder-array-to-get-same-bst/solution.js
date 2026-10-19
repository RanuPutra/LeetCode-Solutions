/**
 * @param {number[]} nums
 * @return {number}
 */
var numOfWays = function(nums) {
    const MOD = 1000000007n;
    const n = nums.length;

    // Pascal's Triangle for combinations using BigInt
    const comb = Array.from({ length: n + 1 }, () => Array(n + 1).fill(0n));
    for (let i = 0; i <= n; i++) {
        comb[i][0] = 1n;
        for (let j = 1; j <= i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }

    function dfs(arr) {
        if (arr.length <= 2) return 1n;

        const left = [];
        const right = [];
        const root = arr[0];

        // Partisi elemen subtree kiri dan kanan
        for (let i = 1; i < arr.length; i++) {
            if (arr[i] < root) {
                left.push(arr[i]);
            } else {
                right.push(arr[i]);
            }
        }

        const leftWays = dfs(left);
        const rightWays = dfs(right);

        const lSize = left.length;
        const rSize = right.length;

        // C(L + R, L) * ways(left) * ways(right) % MOD
        let total = comb[lSize + rSize][lSize];
        total = (total * leftWays) % MOD;
        total = (total * rightWays) % MOD;

        return total;
    }

    // Kurangi 1 karena array awal tidak dihitung sebagai "reorder"
    return Number((dfs(nums) - 1n + MOD) % MOD);
};
