function getCommon(nums1: number[], nums2: number[]): number {
    let i: number = 0;
    let j: number = 0;
    const n1: number = nums1.length;
    const n2: number = nums2.length;

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
}
