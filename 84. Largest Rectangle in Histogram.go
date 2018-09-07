/*
84. Largest Rectangle in Histogram

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.
 

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/

//solution one
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

//solution two
func largestRectangleArea(heights []int) int {
	heightlen := len(heights)
	if heightlen == 0 {
		return 0
	}

	left := make([]int, heightlen)
	right := make([]int, heightlen)
	left[0] = -1
	right[heightlen-1] = heightlen
	largest := 0

	for i := 1; i < heightlen; i++ {
		p := i - 1
		for p >= 0 && heights[p] >= heights[i] {
			p = left[p]
		}
		left[i] = p
	}
	for i := heightlen - 2; i >= 0; i-- {
		p := i + 1
		for p < heightlen && heights[p] >= heights[i] {
			p = right[p]
		}
		right[i] = p
	}

	for i := 0; i < heightlen; i++ {
		largest = max(largest, heights[i]*(right[i]-left[i]-1))
	}
	return largest
}