package main

import "fmt"

/*
슬라이스의 length: len(s) 슬라이스가 포함하고 있는 원소의 개수

슬라이스의 capacity: cap(s) 슬라이스가 가리키는 배열에서 슬라이스의 첫번째 원소부터 센 원소의 개수
*/

func main() {
	fmt.Println("함수 make로 가변 길이 배열 만들기")
	/*
		a := make([]int, 5)의     len = 5 cap = 5 [0 0 0 0 0]
		b := make([]int, 0, 5)의  len = 0 cap = 5 []
		c := b[:2]의              len = 2 cap = 5 [0 0]
		d := c[2:5]의             len = 3 cap = 3 [0 0 0]
		d = append(d, 1,2,3)후    len = 6 cap = 6 [0 0 0 1 2 3]
	*/

	a := make([]int, 5)
	fmt.Printf("a := make([]int, 5)의 \t")
	printSlice(a)

	b := make([]int, 0, 5)
	fmt.Printf("b := make([]int, 0, 5)의\t")
	printSlice(b)

	c := b[:2]
	fmt.Printf("c := b[:2]의\t\t")
	printSlice(c)

	d := c[2:5]
	fmt.Printf("d := c[2:5]의\t\t")
	printSlice(d)

	// 한번에 여러개 원소를 추가할 수 있습니다.
	d = append(d, 1, 2, 3)
	fmt.Printf("d = append(d, 1,2,3)후\t")
	printSlice(d)
}

func printSlice(s []int) {
	fmt.Printf("len = %d cap = %d %v\n", len(s), cap(s), s)
}
