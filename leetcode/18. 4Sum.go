/*
18. 4Sum

Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

func fourSum(nums []int, target int) [][]int {
	//return if nums's length less than 4
	if len(nums) < 4 {
		return [][]int{}
	}
	//res: returned variable
	res := make([][]int, 0)
	//sort the array nums
	usefulfuncs.InsertSort(nums)
	//the main loop: try to find correct array
	for i := 0; i < len(nums)-3; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		for j := i + 1; j < len(nums)-2; j++ {
			if j-1 != i && nums[j] == nums[j-1] {
				continue
			}
			m, n := j+1, len(nums)-1
			for m < n {
				sum := nums[i] + nums[j] + nums[m] + nums[n]
				if sum > target {
					n--
				} else if sum < target {
					m++
				} else {
					res = append(res, []int{nums[i], nums[j], nums[m], nums[n]})
					for m+1 < len(nums) && nums[m] == nums[m+1] {
						m++
					}
					for n > 0 && nums[n] == nums[n-1] {
						n--
					}
					m++
					n--
				}
			}
		}
	}
	return res
}