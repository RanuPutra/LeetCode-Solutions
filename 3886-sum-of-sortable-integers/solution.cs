using System;

public class Solution {
    public int SortableIntegers(int[] nums) {
        int n = nums.Length;

        bool IsSortable(int k) {
            int prevMax = -1;

            for (int i = 0; i < n; i += k) {
                int dropCount = 0;
                int minVal = nums[i];
                int maxVal = nums[i];

                for (int j = 0; j < k; ++j) {
                    int cur = nums[i + j];
                    int next = nums[i + (j + 1) % k];

                    minVal = Math.Min(minVal, cur);
                    maxVal = Math.Max(maxVal, cur);

                    if (cur > next) {
                        dropCount++;
                    }
                }

                // Jika terjadi penurunan lebih dari 1 kali secara siklik, blok tidak bisa diurutkan
                if (dropCount > 1) {
                    return false;
                }

                // Cek apakah nilai minimum blok ini >= nilai maksimum blok sebelumnya
                if (prevMax != -1 && minVal < prevMax) {
                    return false;
                }

                prevMax = maxVal;
            }

            return true;
        }

        int totalSum = 0;

        // Periksa semua pembagi k dari n
        for (int k = 1; k * k <= n; ++k) {
            if (n % k == 0) {
                if (IsSortable(k)) {
                    totalSum += k;
                }
                if (k * k != n) {
                    int k2 = n / k;
                    if (IsSortable(k2)) {
                        totalSum += k2;
                    }
                }
            }
        }

        return totalSum;
    }
}
