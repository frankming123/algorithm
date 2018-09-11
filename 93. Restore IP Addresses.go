/*
93. Restore IP Addresses

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
*/

func restoreIpAddresses(s string) []string {
	res := []string{}
	backTrack(s, &[]string{}, &res, 0)
	return res
}

func backTrack(s string, ip *[]string, res *[]string, count int) {
	if count == 4 && len(s) == 0 {
		*res = append(*res, strings.Join(*ip, "."))
	}
	if count == 4 || len(s) == 0 {
		return
	}

	*ip = append(*ip, string(s[0]))
	backTrack(s[1:], ip, res, count+1)
	*ip = (*ip)[:len(*ip)-1]

	if s[0] != '0' && len(s) >= 2 {
		*ip = append(*ip, s[:2])
		backTrack(s[2:], ip, res, count+1)
		*ip = (*ip)[:len(*ip)-1]
	}

	if len(s) >= 3 && s[0] != '0' && ((s[0] == '1') || (s[0] == '2' && ((s[1] == '5' && s[2] <= '5') || (s[1] < '5')))) {
		*ip = append(*ip, s[:3])
		backTrack(s[3:], ip, res, count+1)
		*ip = (*ip)[:len(*ip)-1]
	}
}