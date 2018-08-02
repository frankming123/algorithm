/*
1. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

//it is a brute force approach
func twoSum(nums []int, target int) []int {
	nLen:=len(nums)
	for i:=0;i<nLen-1;i++{
		for j:=i+1;j<nLen;j++{
			if nums[i]+nums[j]==target{
				return []int{i,j}
			}
		}
	}
	return nil
}