/*
57. Insert Interval

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]

Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]

Output: [[1,2],[3,10],[12,16]]

Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/

type Interval struct {
	Start int
	End   int
}

func insert(intervals []Interval, newInterval Interval) []Interval {
	if len(intervals) == 0 {
		return []Interval{newInterval}
	}
	if intervals[len(intervals)-1].End < newInterval.Start {
		intervals = append(intervals, newInterval)
		return intervals
	}
	if intervals[0].Start > newInterval.End {
		res := []Interval{newInterval}
		res = append(res, intervals...)
		return res
	}
	res := make([]Interval, 0)
	start, end := 0, 0
	for i := 0; i < len(intervals); i++ {
		if intervals[i].End >= newInterval.Start {
			start = i
			break
		}
	}
	for i := 0; i < len(intervals); i++ {
		if intervals[i].Start <= newInterval.End {
			end = i
		}
	}

	for i := 0; i < start; i++ {
		res = append(res, intervals[i])
	}
	res = append(res, Interval{Min(intervals[start].Start, newInterval.Start), Max(intervals[end].End, newInterval.End)})
	for i := end + 1; i < len(intervals); i++ {
		res = append(res, intervals[i])
	}
	return res
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