/*
4. Median of Two Sorted Arrays

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

 

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

//merge two sorted arrays as a big sorted array, and then find its median
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	//try to merge the two arrays: nums1 and nums2
	nums := make([]int, 0)
	var i, j int
	for i < len(nums1) && j < len(nums2) {
		if nums1[i] <= nums2[j] {
			nums = append(nums, nums1[i])
			i++
		} else {
			nums = append(nums, nums2[j])
			j++
		}
	}
	if i == len(nums1) {
		nums = append(nums, nums2[j:]...)
	} else {
		nums = append(nums, nums1[i:]...)
	}
	//find median of array: nums
	nLen := len(nums)
	if nLen%2 == 1 {
		return float64(nums[nLen/2])
	} else {
		return float64(nums[nLen/2]+nums[nLen/2-1]) / 2
	}
}
