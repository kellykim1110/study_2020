package main

import (
	"bytes"
	"fmt"
)

func solution(n int) string {
	var buf bytes.Buffer

	for i := 0; i < n; i++ {
		if i%2 == 0 {
			buf.WriteString("수")
		} else {
			buf.WriteString("박")
		}
	}

	return buf.String()
}

func main() {
	n := 3
	fmt.Println(solution(n))
}
