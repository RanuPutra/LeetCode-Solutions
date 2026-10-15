using System;
using System.Collections.Generic;

public class Solution {
    public int SumCounts(IList<int> nums) {
        int totalSum = 0;
        int n = nums.Count;
        
        for (int i = 0; i < n; ++i) {
            HashSet<int> distinctElements = new HashSet<int>();
            for (int j = i; j < n; ++j) {
                // Tambahkan elemen ke set
                distinctElements.Add(nums[j]);
                
                // Jumlah elemen unik dalam subarray nums[i..j]
                int count = distinctElements.Count;
                
                // Tambahkan kuadrat dari jumlah elemen unik ke total
                totalSum += count * count;
            }
        }
        
        return totalSum;
    }
}
