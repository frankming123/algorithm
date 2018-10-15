/*
40. Combination Sum II

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,

A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5,

A solution set is:
[
  [1,2,2],
  [5]
]
*/

func combinationSum2(candidates []int, target int) [][]int {
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
		if i > start && candidates[i] == candidates[i-1] {
			continue
		}
		*tmplist = append(*tmplist, candidates[i])
		backTrack(candidates, res, tmplist, remain-candidates[i], i+1)
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