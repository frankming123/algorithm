/*
90. Subsets II


Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]

Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

func subsetsWithDup(nums []int) [][]int {
	sort.Slice(nums, func(i, j int) bool {
		if nums[i] < nums[j] {
			return true
		}
		return false
	})
	res := [][]int{}
	backTrack(nums, &[]int{}, &res, 0)
	return res
}

func backTrack(nums []int, array *[]int, res *[][]int, start int) {
	cpy := make([]int, len(*array))
	copy(cpy, *array)
	*res = append(*res, cpy)

	for i := start; i < len(nums); i++ {
		if i > start && nums[i] == nums[i-1] {
			continue
		}
		*array = append(*array, nums[i])
		backTrack(nums, array, res, i+1)
		*array = (*array)[:len(*array)-1]
	}
}