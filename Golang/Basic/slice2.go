package main

/*
슬라이스는 길이없는 배열 리터럴과 같다.

배열 리터럴 예시
[3]bool{true, true, false}

그 배열을 참조하는 슬라이스
[]bool{true, true, false}
*/

import "fmt"

func main() {
	fmt.Println("슬라이스 리터럴 선언")

	fmt.Println("기본형 슬라이스 리터럴")
	q := []int{2, 3, 4, 5, 6, 13}
	fmt.Println(q)

	fmt.Println("구조체 슬라이스 리터럴")
	s := []struct {
		i int
		b bool
	}{
		{2, true},
		{3, false},
		{4, true},
		{5, true},
		{6, false},
		{13, false},
	}
	fmt.Println(s)

	fmt.Println("슬라이스를 슬라이스")
	q = q[:2]
	fmt.Println("q[:2]:", q)

	q = q[1:]
	fmt.Println("q[1:]:", q)
}
