package main

import "fmt"

func main() {
	fmt.Println(solution("abcde"))
	fmt.Println(solution("qwer"))
}

func solution(s string) string {
	if len(s)%2 == 0 {
		return s[len(s)/2-1 : len(s)/2+1]
	} else {
		return string(s[len(s)/2])
	}
}
