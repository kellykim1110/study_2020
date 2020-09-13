package main

import "fmt"

func add1(x int, y int) int {
	return x + y
}

func add2(x, y int) int {
	return x + y
}

func main() {
	fmt.Println("자료형이 서로 같을 때 각각 자료형을 지정하던지 \n아니면 변수명을 다쓰고 자료형을 마지막에 지정하던지 하면 된다.")
	fmt.Println("4+3=", add1(4, 3))
	fmt.Println("4+3=", add2(4, 3))
}
