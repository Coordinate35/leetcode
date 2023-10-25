package main

import (
	"fmt"
	"strings"
)

func removeDuplicateBlank(s string) string {
	var buf strings.Builder

	length := len(s)
	for i := 0; i < length; i++ {
		if string(s[i]) != " " {
			buf.WriteString(string(s[i]))
		}
		if string(s[i]) == " " {
			buf.WriteString(" ")
			for string(s[i+1]) == " " {
				i += 1
			}
		}
	}

	return buf.String()
}

func reverseString(s string, start int, end int) string {
	buf := []byte(s)
	for start < end {
		tmp := buf[start]
		buf[start] = buf[end]
		buf[end] = tmp

		start += 1
		end -= 1
	}
	return string(buf)
}

func reverseWords(s string) string {
	trimed := strings.Trim(s, " ")

	if len(trimed) == 0 {
		return ""
	}

	formulated := removeDuplicateBlank(trimed)

	base := reverseString(formulated, 0, len(formulated)-1)

	start := 0
	length := len(base)
	for i := start; i < length; i++ {
		if string(base[i]) == " " {
			base = reverseString(base, start, i-1)
			start = i + 1
		}
	}
	base = reverseString(base, start, length-1)
	return base
}

func main() {
	result := reverseWords("the sky is blue")
	fmt.Println(result)
}
