/*
47. Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]

Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

//It is amazing that I just trucate the array from last question, and the elements in it are all unique!
func permuteUnique(nums []int) [][]int {
	nMap := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		if _, ok := nMap[nums[i]]; ok {
			nMap[nums[i]]++
		} else {
			nMap[nums[i]] = 1
		}
	}

	multi := 1
	retain := len(nums)
	for _, v := range nMap {
		multi *= combination(v, retain)
		retain -= v
	}

	res := make([][]int, multi)
	res[0] = nums
	for i := 1; i < multi; i++ {
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

func combination(up, down int) int {
	return factorial(down) / (factorial(up) * factorial(down-up))
}