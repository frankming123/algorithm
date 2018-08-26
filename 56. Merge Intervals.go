/*
56. Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]

Output: [[1,6],[8,10],[15,18]]

Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: [[1,4],[4,5]]

Output: [[1,5]]

Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
*/

type Interval struct {
	Start int
	End   int
}

//approach 1
func merge(intervals []Interval) []Interval {
	isSucceed := true
	for i := 0; i < len(intervals); i++ {
		for j := i + 1; j < len(intervals); j++ {
			if intervals[i].Start <= intervals[j].End && intervals[i].End >= intervals[j].Start {
				isSucceed = false
				break
			}
		}
	}
	if isSucceed {
		return intervals
	}

	res := make([]Interval, 0)
	for i := 0; i < len(intervals); i++ {
		isExist := false
		for j := 0; j < len(res); j++ {
			if intervals[i].Start <= res[j].End && intervals[i].End >= res[j].Start {
				res[j].End = usefulfuncs.Max(res[j].End, intervals[i].End)
				res[j].Start = usefulfuncs.Min(res[j].Start, intervals[i].Start)
				isExist = true
				break
			}
		}

		if !isExist {
			res = append(res, intervals[i])
		}
	}
	return merge(res)
}

//approach 2
func merge(intervals []Interval) []Interval {
	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i].Start > intervals[j].Start {
			return false
		}
		return true
	})
	res := make([]Interval, 0)
	for _, v := range intervals {
		if len(res) == 0 || res[len(res)-1].End < v.Start {
			res = append(res, v)
		} else {
			res[len(res)-1].End = usefulfuncs.Max(res[len(res)-1].End, v.End)
		}
	}
	return res
}