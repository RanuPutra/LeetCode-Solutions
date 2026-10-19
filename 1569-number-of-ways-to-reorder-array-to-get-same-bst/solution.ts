function numOfWays(nums: number[]): number {
    const MOD: bigint = 1000000007n;
    const n: number = nums.length;

    // Pascal's Triangle for combinations using BigInt
    const comb: bigint[][] = Array.from({ length: n + 1 }, () => Array(n + 1).fill(0n));
    for (let i = 0; i <= n; i++) {
        comb[i][0] = 1n;
        for (let j = 1; j <= i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }

    function dfs(arr: number[]): bigint {
        if (arr.length <= 2) return 1n;

        const left: number[] = [];
        const right: number[] = [];
        const root: number = arr[0];

        // Partisi elemen subtree kiri dan kanan
        for (let i = 1; i < arr.length; i++) {
            if (arr[i] < root) {
                left.push(arr[i]);
            } else {
                right.push(arr[i]);
            }
        }

        const leftWays: bigint = dfs(left);
        const rightWays: bigint = dfs(right);

        const lSize: number = left.length;
        const rSize: number = right.length;

        // C(L + R, L) * ways(left) * ways(right) % MOD
        let total: bigint = comb[lSize + rSize][lSize];
        total = (total * leftWays) % MOD;
        total = (total * rightWays) % MOD;

        return total;
    }

    // Kurangi 1 karena array awal tidak dihitung sebagai "reorder"
    return Number((dfs(nums) - 1n + MOD) % MOD);
}
