#include <stdbool.h>

static bool is_sortable(const int* nums, int n, int k) {
    int prev_max = -1;

    for (int i = 0; i < n; i += k) {
        int drop_count = 0;
        int min_val = nums[i];
        int max_val = nums[i];

        for (int j = 0; j < k; ++j) {
            int cur = nums[i + j];
            int next = nums[i + (j + 1) % k];

            if (cur < min_val) min_val = cur;
            if (cur > max_val) max_val = cur;

            if (cur > next) {
                drop_count++;
            }
        }

        // Jika terjadi penurunan lebih dari 1 kali secara siklik, blok tidak bisa diurutkan
        if (drop_count > 1) {
            return false;
        }

        // Cek apakah nilai minimum blok ini >= nilai maksimum blok sebelumnya
        if (prev_max != -1 && min_val < prev_max) {
            return false;
        }

        prev_max = max_val;
    }

    return true;
}

int sortableIntegers(int* nums, int numsSize) {
    int n = numsSize;
    int total_sum = 0;

    // Periksa semua pembagi k dari n
    for (int k = 1; k * k <= n; ++k) {
        if (n % k == 0) {
            if (is_sortable(nums, n, k)) {
                total_sum += k;
            }
            if (k * k != n) {
                int k2 = n / k;
                if (is_sortable(nums, n, k2)) {
                    total_sum += k2;
                }
            }
        }
    }

    return total_sum;
}
