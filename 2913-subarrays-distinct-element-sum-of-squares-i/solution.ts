function sumCounts(nums: number[]): number {
    let totalSum: number = 0;
    const n: number = nums.length;

    for (let i = 0; i < n; i++) {
        const distinctElements = new Set<number>();
        for (let j = i; j < n; j++) {
            // Tambahkan elemen ke Set
            distinctElements.add(nums[j]);

            // Ukuran Set adalah jumlah elemen unik dalam subarray nums[i..j]
            const count: number = distinctElements.size;

            // Tambahkan kuadrat dari jumlah elemen unik ke total
            totalSum += count * count;
        }
    }

    return totalSum;
}
