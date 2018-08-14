/*
31. Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

func nextPermutation(nums []int) {
	var i, j, k int
	for a := len(nums) - 2; a >= 0; a-- {
		if nums[a] < nums[a+1] {
			i = a
			j = a + 1
			break
		}
	}
	for a := len(nums) - 1; a >= j; a-- {
		if nums[a] > nums[i] {
			k = a
			break
		}
	}
	nums[i], nums[k] = nums[k], nums[i]
	for a := j; a <= (len(nums)-1+j)/2; a++ {
		nums[a], nums[len(nums)-1-a+j] = nums[len(nums)-1-a+j], nums[a]
	}
}

/*
reference:

https://www.cnblogs.com/eudiwffe/p/6260699.html
*/