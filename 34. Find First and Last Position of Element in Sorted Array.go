/*
34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8

Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6

Output: [-1,-1]
*/

func searchRange(nums []int, target int) []int {
	if len(nums) == 0 {
		return []int{-1, -1}
	}
	left := 0
	right := len(nums)
	ind := 0
	res := make([]int, 2)

	for left < right {
		middle := (right-left)/2 + left
		if nums[middle] < target {
			left = middle + 1
		} else if nums[middle] > target {
			right = middle
		} else {
			left = middle
			break
		}
	}
	ind = left

	if ind == len(nums) || nums[ind] != target {
		return []int{-1, -1}
	}

	for i := ind; i >= 0 && nums[i] == target; i-- {
		res[0] = i
	}
	for i := ind; i < len(nums) && nums[i] == target; i++ {
		res[1] = i
	}

	return res
}