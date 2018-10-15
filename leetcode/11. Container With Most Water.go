/*
11. Container With Most Water

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

...

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

 

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

//two-layer loop, find the smaller one of two elements, calculate the result and compare to the variable max
func maxArea1(height []int) int {
	max := 0
	for i := 0; i < len(height); i++ {
		for j := i + 1; j < len(height); j++ {
			max = Max(max, Min(height[i], height[j])*(j-i))
		}
	}
	return max
}

func Max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func Min(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

//another approach
func maxArea2(height []int) int {
	//store the max area
	max := 0
	//assert the left pointer and right pointer
	i, j := 0, len(height)-1
	//move the shorter one until i==j
	for i < j {
		if height[i] > height[j] {
			max = Max(max, height[j]*(j-i))
			j--
		} else {
			max = Max(max, height[i]*(j-i))
			i++
		}
	}

	return max
}