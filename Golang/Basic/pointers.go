package main

/*
nil: zero value
&i: i를 가르키는 포인터
*p: 포인터p가 기리키는 값

포인터 연산은 Golang에서 불가
*/

import "fmt"

func main() {
	i, j := 16, 2020

	p := &i // i를 가르키는 포인터
	fmt.Println(*p)

	*p = 9
	fmt.Println(i)

	p = &j
	*p = *p / 20
	fmt.Println(j)
}
