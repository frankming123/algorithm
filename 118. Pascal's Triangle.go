/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5

Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

func generate(numRows int) [][]int {
	res := make([][]int, numRows)
	init := []int{1}
	for i := 0; i < numRows; i++ {
		res[i] = init
		init = generateOne(init)
	}
	return res
}

func generateOne(nums []int) []int {
	res := make([]int, len(nums)+1)
	res[0] = nums[0]
	for i := 0; i < len(nums)-1; i++ {
		res[i+1] = nums[i] + nums[i+1]
	}
	res[len(nums)] = nums[len(nums)-1]
	return res
}
