/*
46. Permutations

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]

Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

func permute(nums []int) [][]int {
	sum := factorial(len(nums))
	res := make([][]int, sum)
	res[0] = nums
	for i := 1; i < sum; i++ {
		res[i] = nextPermute(res[i-1])
	}
	return res
}

func nextPermute(numss []int) []int {
	nums := make([]int, len(numss))
	for i := 0; i < len(numss); i++ {
		nums[i] = numss[i]
	}
	left, right := -1, 0
	for i := len(nums) - 2; i >= 0; i-- {
		if nums[i] < nums[i+1] {
			left = i
			break
		}
	}
	if left != -1 {
		for i := len(nums) - 1; i > left; i-- {
			if nums[i] > nums[left] {
				right = i
				break
			}
		}
		nums[left], nums[right] = nums[right], nums[left]
	}
	for i := left + 1; i < (len(nums)+left+1)/2; i++ {
		nums[i], nums[len(nums)-i+left] = nums[len(nums)-i+left], nums[i]
	}
	return nums
}

func factorial(num int) int {
	res := 1
	for i := 1; i <= num; i++ {
		res *= i
	}
	return res
}