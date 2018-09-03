/*
78. Subsets

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]

Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

func subsets(nums []int) [][]int {
	res := [][]int{}
	backTrack(&res, &[]int{}, nums, 0)
	return res
}

func backTrack(arrays *[][]int, array *[]int, nums []int, start int) {
	cpy := make([]int, len(*array))
	copy(cpy, *array)
	*arrays = append(*arrays, cpy)

	for i := start; i < len(nums); i++ {
		*array = append(*array, nums[i])
		backTrack(arrays, array, nums, i+1)
		*array = (*array)[:len(*array)-1]
	}
}