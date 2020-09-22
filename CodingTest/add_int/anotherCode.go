package main

import "fmt"

func main() {
	fmt.Println(solution(6, 3))
	fmt.Println(solution(4, 9))
	fmt.Println(solution(5, 5))
}

// 정수 합 공식 이용하기
func solution(a int, b int) int64 {
	A := int64(a)
	B := int64(b)
	if A > B {
		return (A + B) * (A - B + 1) / 2
	} else if A < B {
		return (B + A) * (B - A + 1) / 2
	} else {
		return A
	}
}
