package main

import (
	"fmt"
)

func solution(n int) string {
	res := ""
	for i := 0; i < n; i++ {
		if i == 0 || i%2 == 0 {
			res = res + "수"
		} else {
			res = res + "박"
		}
	}
	return res
}

func main() {
	n := 3
	fmt.Println(solution(n))
}
