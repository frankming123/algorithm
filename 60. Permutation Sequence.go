/*
60. Permutation Sequence

The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"

Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.

Given k will be between 1 and n! inclusive.

Example 1:

Input: n = 3, k = 3

Output: "213"

Example 2:

Input: n = 4, k = 9

Output: "2314"
*/

func getPermutation(n int, k int) string {
	s := make([]byte, n)
	for i := 1; i <= n; i++ {
		s[i-1] = byte(i) + '0'
	}
	res := string(s)
	for i := 1; i < k; i++ {
		res = getNext(res)
	}
	return res
}

func getNext(s string) string {
	sarray := []byte(s)
	left := -1
	for i := len(sarray) - 1; i >= 1; i-- {
		if sarray[i] > sarray[i-1] {
			left = i - 1
			break
		}
	}
	if left != -1 {
		right := len(sarray) - 1
		for i := len(sarray) - 1; i > left; i-- {
			if sarray[i] > sarray[left] {
				right = i
				break
			}
		}
		sarray[left], sarray[right] = sarray[right], sarray[left]
	}
	exchange := sarray[left+1:]
	for i := 0; i < len(exchange)/2; i++ {
		exchange[i], exchange[len(exchange)-1-i] = exchange[len(exchange)-1-i], exchange[i]
	}
	return string(sarray)
}