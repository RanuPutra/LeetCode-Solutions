/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var getCommon = function(nums1, nums2) {
    let i = 0, j = 0;
    const n1 = nums1.length, n2 = nums2.length;

    while (i < n1 && j < n2) {
        if (nums1[i] === nums2[j]) {
            return nums1[i]; // Elemen terkecil yang sama ditemukan
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return -1; // Tidak ada elemen yang sama
};
