/*
39. Combination Sum

Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [2,3,6,7], target = 7,

A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:

Input: candidates = [2,3,5], target = 8,

A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

func combinationSum(candidates []int, target int) [][]int {
	res := make([][]int, 0)
	InsertSort(candidates)
	backTrack(candidates, &res, &[]int{}, target, 0)
	return res
}

func backTrack(candidates []int, res *[][]int, tmplist *[]int, remain, start int) {
	if remain < 0 {
		return
	}
	if remain == 0 {
		tmp := make([]int, len(*tmplist))
		copy(tmp, *tmplist)
		*res = append(*res, tmp)
		return
	}
	for i := start; i < len(candidates); i++ {
		*tmplist = append(*tmplist, candidates[i])
		backTrack(candidates, res, tmplist, remain-candidates[i], i)
		*tmplist = (*tmplist)[:len(*tmplist)-1]
	}
}

func InsertSort(nums []int) {
	for i := 1; i < len(nums); i++ {
		for j := i - 1; j >= 0 && nums[j] > nums[j+1]; j-- {
			nums[j], nums[j+1] = nums[j+1], nums[j]
		}
	}
}