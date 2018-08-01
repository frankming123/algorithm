//cut the last digit of x, then add it to ouput
func reverse(x int) int {
	output := 0
	for x != 0 {
		a := x % 10
		output = output*10 + a
		x /= 10
	}

	if output >= 2<<30 || output < (-2<<30) {
		return 0
	}

	return output
}
