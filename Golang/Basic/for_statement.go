package main

import "fmt"

func main() {
	sum := 0
	for i := 0; i < 10; i++ { //init statement ; condition expression ; post statement
		sum += i
	}
	fmt.Println(sum)

	/*
		Golang에서 반복문은 for문이 유일하다.
		while문을 써야 할 경우 아래와 같이 흉내를 낸다.
	*/
	while_sum := 0
	j := 0
	for j < 10 {
		while_sum += j
		j++
	}
	fmt.Println(while_sum)
}
