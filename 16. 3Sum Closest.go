/*
16. 3Sum Closest

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

//I decide to use another package called "usefulfunc" to store some common and useful functions
func threeSumClosest(nums []int, target int) int {
	useful_funcs.InsertSort(nums)
	sum := nums[0] + nums[1] + nums[2]

	for i := 0; i < len(nums)-2 && nums[i] <= target; i++ {
		j, k := i+1, len(nums)-1
		for j < k {
			tmp := nums[i] + nums[j] + nums[k]
			if useful_funcs.Abs(tmp-target) < useful_funcs.Abs(sum-target) {
				sum = tmp
			}

			if tmp > target {
				k--
			} else if tmp < target {
				j++
			} else {
				return sum
			}
		}
	}
	return sum
}