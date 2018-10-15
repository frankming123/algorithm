/*
68. Text Justification

Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.

Example 1:

Input:

words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16

Output:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Example 2:

Input:

words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16

Output:

[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]

Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
			 Note that the second line is also left-justified becase it contains only one word.
			 
Example 3:

Input:

words = ["Science","is","what","we","understand","well","enough","to","explain",
		 "to","a","computer.","Art","is","everything","else","we","do"]
		 
maxWidth = 20

Output:

[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/

func fullJustify(words []string, maxWidth int) []string {
	res := make([]string, 0)
	count := 0
	left := 0
	for i := 0; i < len(words); i++ {
		if count+len(words[i]) > maxWidth-i+left {
			str := ""
			if i-left-1 > 0 {
				//calculate the space needed
				spaceNum := (maxWidth - count) / (i - left - 1)
				extraSpaceNum := (maxWidth - count) % (i - left - 1)
				for j := 0; j < extraSpaceNum; j++ {
					str += fmt.Sprintf("%s%*s", words[left+j], spaceNum+1, "")
				}
				for j := extraSpaceNum; j < i-left-1; j++ {
					str += fmt.Sprintf("%s%*s", words[left+j], spaceNum, "")
				}
				str += words[i-1]
			} else {
				str += fmt.Sprintf("%s%*s", words[i-1], maxWidth-len(words[i-1]), "")
			}
			res = append(res, str)
			count = len(words[i])
			left = i
		} else {
			count += len(words[i])
		}
	}
	//the last line
	str := ""
	for i := left; i < len(words)-1; i++ {
		str += words[i] + " "
	}
	str += words[len(words)-1]
	str += fmt.Sprintf("%*s", maxWidth-len(str), "")
	res = append(res, str)
	return res
}