/*
53. Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],

Output: 6

Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

//two points. One moves from left to right, the other moves when sum < 0
func maxSubArray(nums []int) int {
	left := 0
	sum := 0
	max := nums[0]
	for i := 0; i < len(nums); i++ {
		sum += nums[i]
		max = Max(max, sum)
		if sum < 0 {
			for j := left; j <= i; j++ {
				sum -= nums[j]
			}
			left = i + 1
		}
	}
	return max
}

func Max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}