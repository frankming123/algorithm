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
