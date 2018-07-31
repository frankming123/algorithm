//It is so hard that takes me half a day-.-
/*
make "123456789abcdef",4 as instance:

graph:
1     7     d
2   6 8   c e
3 5   9 b   f
4     a

output:
"17d268ce359bf4a"

solution:
step 1: 2*numRows-2 as a round,then cut the input string to an array:
[123456,789abc,def]

step 2: transpose the array to a new array:
[17d,28e,39f,4a,5b,6c]

step 3: join medial elements of the array by specific order(i,2*numRows-i-2,i is not 0 and numRows-1):
[17d,268ce,359bf,4a]

step 4: join all elements of the array as a string:
"17d268ce359bf4a"

*/
func convert(s string, numRows int) string {
	//return s straight if numRows is 1
	if numRows == 1 || numRows >= len(s) {
		return s
	}
	//res: the returned string
	res := make([]byte, 0)
	//elements a round
	n := 2*numRows - 2
	//k: the number of rounds
	k := len(s)/n + 1
	//strArr: cuted array of s
	strArr := make([][]byte, k)

	for i := 0; i < k; i++ {
		if i*n+n > len(s) {
			strArr[i] = []byte(s[i*n:])
		} else {
			strArr[i] = []byte(s[i*n : i*n+n])
		}
	}

	//strArr2: transposed strArr
	strArr2 := MatrixTranspose(strArr)

	fmt.Println(strArr2)
	//last: join the strings, and return
	res = append(res, strArr2[0]...)
	for i := 1; i < numRows-1; i++ {
		if n-i < len(strArr2) {
			res = append(res, stringOneByOne(string(strArr2[i]), string(strArr2[n-i]))...)
		} else {
			res = append(res, strArr2[i]...)
		}
	}
	res = append(res, strArr2[numRows-1]...)

	return string(res)
}

func MatrixTranspose(matrix [][]byte) [][]byte {
	res := make([][]byte, len(matrix[0]))
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[i]); j++ {
			res[j] = append(res[j], matrix[i][j])
		}
	}
	return res
}

func stringOneByOne(s1, s2 string) string {
	s1Len := len(s1)
	s2Len := len(s2)

	res := make([]byte, 0)

	for i := 0; i < Min(s1Len, s2Len); i++ {
		res = append(res, s1[i])
		res = append(res, s2[i])
	}

	if s1Len > s2Len {
		res = append(res, s1[s2Len:]...)
	}
	if s2Len > s1Len {
		res = append(res, s2[s1Len:]...)
	}

	return string(res)
}

func Min(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}
