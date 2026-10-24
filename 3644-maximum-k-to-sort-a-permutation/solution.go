package main

func sortPermutation(nums []int) int {
	ans := -1
	for i, x := range nums {
		if x != i {
			if ans == -1 {
				ans = x
			} else {
				ans &= x
			}
		}
	}
	if ans == -1 {
		return 0
	}
	return ans
}
