package main

import (
	"fmt"
	"strings"
)

func solution(n int) string {

	arr := make([]string, n)

	for i := range arr {
		if i%2 == 0 {
			arr[i] = "수"
		} else {
			arr[i] = "박"
		}
	}

	return strings.Join(arr, "")
}

func main() {
	n := 3
	fmt.Println(solution(n))
}
