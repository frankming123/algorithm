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