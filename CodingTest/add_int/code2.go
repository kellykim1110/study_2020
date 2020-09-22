package main

import "fmt"

func solution(a int, b int) int64 {
	// a는 무조건 작은 수, b는 무조건 큰 수로 만들어 버리기
	if a > b {
		temp := b
		b = a
		a = temp
	}

	sum := 0
	for i := a; i <= b; i++ {
		// 출력값의 자료형이 int64이므로 int를 int64로 변경
		sum += int64(i)
	}
	return sum
}

func main() {
	fmt.Println(solution(6, 3))
	fmt.Println(solution(4, 9))
	fmt.Println(solution(5, 5))
}
