/**
 * @param {number[]} nums
 * @return {number}
 */
var sumCounts = function(nums) {
    let totalSum = 0;
    const n = nums.length;

    for (let i = 0; i < n; i++) {
        const distinctElements = new Set();
        for (let j = i; j < n; j++) {
            // Tambahkan elemen ke Set
            distinctElements.add(nums[j]);

            // Ukuran Set adalah jumlah elemen unik dalam subarray nums[i..j]
            const count = distinctElements.size;

            // Tambahkan kuadrat dari jumlah elemen unik ke total
            totalSum += count * count;
        }
    }

    return totalSum;
};
