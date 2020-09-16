package main

import "fmt"

func main() {
	// var a[n]T
	// 타입 n[T]는 타입T 값을 n개 저장하는 배열이며 배열의 크기는 한번 설정하면 바꿀 수 없다.
	var a [2]string
	a[0] = "Hello"
	a[1] = "World"
	fmt.Println("a[0], a[1]:", a[0], a[1])
	fmt.Println("a:", a)

	// 선언과 배열을 한번에!!
	b := [3]int{20, 9, 16}
	fmt.Println("b:", b)
}
