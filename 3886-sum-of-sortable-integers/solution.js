/**
 * @param {number[]} nums
 * @return {number}
 */
var sortableIntegers = function(nums) {
    const n = nums.length;

    function isSortable(k) {
        let prevMax = -1;

        for (let i = 0; i < n; i += k) {
            let dropCount = 0;
            let minVal = nums[i];
            let maxVal = nums[i];

            for (let j = 0; j < k; j++) {
                const cur = nums[i + j];
                const next = nums[i + (j + 1) % k];

                minVal = Math.min(minVal, cur);
                maxVal = Math.max(maxVal, cur);

                if (cur > next) {
                    dropCount++;
                }
            }

            // Jika terjadi penurunan lebih dari 1 kali secara siklik, blok tidak bisa diurutkan
            if (dropCount > 1) {
                return false;
            }

            // Cek apakah nilai minimum blok ini >= nilai maksimum blok sebelumnya
            if (prevMax !== -1 && minVal < prevMax) {
                return false;
            }

            prevMax = maxVal;
        }

        return true;
    }

    let totalSum = 0;

    // Periksa semua pembagi k dari n
    for (let k = 1; k * k <= n; k++) {
        if (n % k === 0) {
            if (isSortable(k)) {
                totalSum += k;
            }
            if (k * k !== n) {
                const k2 = n / k;
                if (isSortable(k2)) {
                    totalSum += k2;
                }
            }
        }
    }

    return totalSum;
};
