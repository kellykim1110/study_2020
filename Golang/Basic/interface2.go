package main

/*
메소드가 하나도 없는 인터페이스를 empty 인터페이스라고 하며,
이 empty 인터페이스는 어떤 타입이던 저장할 수 있다.

interface{}

empty 인터페이스는 보통 타입을 알 수 없는 값을 처리할 때 사용
*/

import "fmt"

/*
	empty interface에 대해
	인터페이스 i의 (값, 타입) : (<nil>, <nil>)
	i = 42에 대해
	인터페이스 i의 (값, 타입) : (42, int)
	i = "hello"에 대해
	인터페이스 i의 (값, 타입) : (hello, string)
*/

func main() {
	fmt.Println("empty interface에 대해")
	var i interface{}
	describe(i)

	fmt.Println("i = 42에 대해")
	i = 42
	describe(i)
	fmt.Println("i = \"hello\"에 대해")
	i = "hello"
	describe(i)
}

func describe(i interface{}) {
	fmt.Printf("인터페이스 i의 (값, 타입) : (%v, %T)\n", i, i)
}
