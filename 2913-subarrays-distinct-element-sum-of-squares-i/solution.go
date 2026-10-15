package main

func sumCounts(nums []int) int {
	totalSum := 0
	n := len(nums)

	for i := 0; i < n; i++ {
		distinctElements := make(map[int]bool)
		for j := i; j < n; j++ {
			// Tambahkan elemen ke map
			distinctElements[nums[j]] = true

			// Panjang map adalah jumlah elemen unik dalam subarray nums[i..j]
			count := len(distinctElements)

			// Tambahkan kuadrat dari jumlah elemen unik ke total
			totalSum += count * count
		}
	}

	return totalSum
}
