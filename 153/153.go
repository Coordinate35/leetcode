func findMin(nums []int) int {
    if len(nums) == 1 {
        return nums[0]
    }

    last_index := len(nums) - 1
    i := last_index / 2

    if i == 0 {
        if nums[i] < nums[i+1] {
            return nums[i]
        }
        return findMin(nums[1:])
    }

    if i == last_index {
        if nums[i] < nums[i-1] {
            return nums[i]
        }
        return findMin(nums[:last_index])
    }

    if nums[i] < nums[i+1] && nums[i] < nums[i-1] {
        return nums[i]
    }
    min1 := findMin(nums[:i])
    min2 := findMin(nums[i+1:])
    if min1 > min2 {
        return min2
    }
    return min1
}
