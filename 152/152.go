package main

import "fmt"

func maxProduct(nums []int) int {
	length := len(nums)

	if length == 0 {
		return 0
	}

	max := make([]int, length)
	min := make([]int, length)

	max[0] = nums[0]
	min[0] = nums[0]

	for i := 1; i < length; i++ {
		max[i] = nums[i]
		min[i] = nums[i]

		if nums[i]*max[i-1] > max[i] {
			max[i] = nums[i] * max[i-1]
		}
		if nums[i]*min[i-1] > max[i] {
			max[i] = nums[i] * min[i-1]
		}

		if nums[i]*max[i-1] < min[i] {
			min[i] = nums[i] * max[i-1]
		}
		if nums[i]*min[i-1] < min[i] {
			min[i] = nums[i] * min[i-1]
		}
	}

	result := max[0]

	for i := 0; i < length; i++ {
		if result < max[i] {
			result = max[i]
		}
	}

	return result
}

func main() {
	// nums1 := []int{2, 3, -2, 4}
	nums2 := []int{-2, 0, -1}
	result := maxProduct(nums2)
	fmt.Println(result)

}
