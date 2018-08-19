/*
42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

//Dynamic Programming
func trap(height []int) int {
	if len(height) < 3 {
		return 0
	}
	leftMax := make([]int, len(height))
	rightMax := make([]int, len(height))
	res := 0

	for i, iMax := 0, 0; i < len(height); i++ {
		if iMax < height[i] {
			iMax = height[i]
		}
		leftMax[i] = iMax
	}
	for i, iMax := len(height)-1, 0; i >= 0; i-- {
		if iMax < height[i] {
			iMax = height[i]
		}
		rightMax[i] = iMax
	}

	for i:=0;i<len(height)-1;i++{
		res+=Min(leftMax[i],rightMax[i])-height[i]
	}
	return res
}

func Min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}