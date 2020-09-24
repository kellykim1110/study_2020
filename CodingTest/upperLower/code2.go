package main

import (
	"fmt"
	"strings"
)

func main() {
	s1 := "The Little Women"
	fmt.Println(solution(s1))
}

func solution(s string) string {
	var answer string

	idx := 0
	for _, value := range s {
		char := string(value)
		if char == " " {
			idx = 0
			answer += char
			continue
		}
		if idx%2 == 0 {
			answer += strings.ToUpper(char)
		} else {
			answer += strings.ToLower(char)
		}
		idx++
	}

	return answer
}
