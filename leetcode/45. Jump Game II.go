/*
45. Jump Game II

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]

Output: 2

Explanation: The minimum number of jumps to reach the last index is 2.
	Jump 1 step from index 0 to 1, then 3 steps to the last index.

Note:

You can assume that you can always reach the last index.
*/

func jump(nums []int) int {
	if len(nums) == 1 {
		return 0
	}
	if nums[0] >= len(nums)-1 {
		return 1
	}

	min := 0
	pos := 0
	for pos < len(nums)-1 {
		pos = maxJump(nums, pos)
		min++
	}
	return min
}

func maxJump(nums []int, ind int) int {
	if nums[ind]+ind >= len(nums)-1 {
		return len(nums) - 1
	}
	max := ind
	for i := ind + 1; i <= nums[ind]+ind; i++ {
		if nums[i]+i > nums[max]+max {
			max = i
		}
	}
	return max
}