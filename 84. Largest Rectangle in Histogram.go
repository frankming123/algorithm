/*
84. Largest Rectangle in Histogram

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.
 

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/

func largestRectangleArea(heights []int) int {
	if len(heights) == 0 {
		return 0
	}
	largestnum := 0

	for i := 0; i < len(heights); i++ {
		count := 0

		for j := 0; j < len(heights); j++ {
			if heights[j] < heights[i] {
				largestnum = max(largestnum, count*heights[i])
				count = 0
			} else {
				count++
			}
		}
		largestnum = max(largestnum, count*heights[i])
	}
	return largestnum
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}