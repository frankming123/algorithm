/*
15. 3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

func threeSum(nums []int) [][]int {
	//return none if length of nums is less than three
	if len(nums) < 3 {
		return [][]int{}
	}
	//use Insert-Sort to sort nums
	InsertSort(nums)
	//some special conditions
	if nums[len(nums)-1] < 0 || nums[0] > 0 {
		return [][]int{}
	} else if nums[len(nums)-1] == 0 {
		if nums[len(nums)-2] == 0 && nums[len(nums)-3] == 0 {
			return [][]int{{0, 0, 0}}
		} else {
			return [][]int{}
		}
	} else if nums[0] == 0 {
		if nums[1] == 0 && nums[2] == 0 {
			return [][]int{{0, 0, 0}}
		} else {
			return [][]int{}
		}
	}
	//the returned array
	res := make([][]int, 0)
	//start to find the unique triplets
	for i := 0; nums[i] <= 0; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		j, k := i+1, len(nums)-1
		for j < k && nums[j]+nums[i] <= 0 {
			sum := nums[i] + nums[j] + nums[k]
			if sum > 0 {
				k--
			} else if sum < 0 {
				j++
			} else {
				res = append(res, []int{nums[i], nums[j], nums[k]})
				for nums[j] == nums[j+1] {
					j++
				}
				for nums[k] == nums[k-1] {
					k--
				}
				j++
				k--
			}
		}
	}
	return res
}

func InsertSort(nums []int) {
	for i := 1; i < len(nums); i++ {
		for j := i - 1; j >= 0 && nums[j] > nums[j+1]; j-- {
			nums[j], nums[j+1] = nums[j+1], nums[j]
		}
	}
}
