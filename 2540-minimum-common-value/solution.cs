public class Solution {
    public int GetCommon(int[] nums1, int[] nums2) {
        int i = 0, j = 0;
        int n1 = nums1.Length, n2 = nums2.Length;

        while (i < n1 && j < n2) {
            if (nums1[i] == nums2[j]) {
                return nums1[i]; // Elemen terkecil yang sama ditemukan
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return -1; // Tidak ada elemen yang sama
    }
}
