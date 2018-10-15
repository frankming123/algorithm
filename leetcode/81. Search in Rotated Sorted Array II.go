/*
81. Search in Rotated Sorted Array II

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0

Output: true

Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3

Output: false

Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
*/

//what different from problem I is that boundary duplicates affect judges to move points left or right,
//so just remove them
func search(nums []int, target int) bool {
	if len(nums) == 0 {
		return false
	}
	if target == nums[0] {
		return true
	} else {
		i := 1
		for i < len(nums) && nums[i] == nums[0] {
			i++
		}
		nums = nums[i:]
	}
	left, right := 0, len(nums)-1
	for left <= right {
		middle := (right-left)/2 + left
		if nums[middle] == target {
			return true
		} else if nums[middle] < target {
			if nums[middle] >= nums[0] {
				left = middle + 1
			} else {
				if target >= nums[0] {
					right = middle - 1
				} else {
					left = middle + 1
				}
			}
		} else {
			if nums[middle] < nums[0] {
				right = middle - 1
			} else {
				if target >= nums[0] {
					right = middle - 1
				} else {
					left = middle + 1
				}
			}
		}
	}
	return false
}