/*
71. Simplify Path

Given an absolute path for a file (Unix-style), simplify it.

For example,

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:

Did you consider the case where path = "/../"?
In this case, you should return "/".

Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

func simplifyPath(path string) string {
	params := strings.Split(path, "/")
	for i := 0; i < len(params); i++ {
		if len(params[i]) == 0 || params[i] == "." {
			params = append(params[:i], params[i+1:]...)
			i--
		} else if params[i] == ".." {
			if i == 0 {
				params = params[1:]
				i--
			} else {
				params = append(params[:i-1], params[i+1:]...)
				i -= 2
			}
		}
	}
	res := "/" + strings.Join(params, "/")
	return res
}