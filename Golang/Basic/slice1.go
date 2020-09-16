package main

/*
배열이 고정 길이인 반면에 슬라이스는 가변 길이이다.
슬라이스를 쓰면 배열을 동적인 것 처럼 쓸 수 있다.

슬라이스를 통해 배열의 값에 접근하거나 값을 수정할 수 있다.
슬라이스의 슬라이스를 만드는 것 또한 가능해 Golang에서는 배열보다 슬라이스를 더 많이 사용
*/

import "fmt"

func main() {
	names := [4]string{
		"Jimi",
		"Jessi",
		"Silber",
		"Gold", // 마지막에 콤마(,)를 해주어야 함
	}
	fmt.Println("배열 names:", names)

	fmt.Println("슬라이스 선언")
	var s1 []string = names[0:3] // 처음에는 var 을 무조건 쓰지만 그 이후의 슬라이스는 선언하지 않아도 된다.
	s2 := names[0:2]

	fmt.Println("names[0:3]:", s1)
	fmt.Println("names[0:2]:", s2)

	fmt.Println("슬라이스 값 변경하기")
	s1[0] = "Dragon"
	fmt.Println("s1[0]=Dragon으로 변경한 후 s1:", s1)
	fmt.Println("s1[0]=Dragon으로 변경한 후 s2:", s2)

	s2 = s1[0:2]
	fmt.Println("s2=s1[0:2]으로 변경한 후 s2:", s2)
}
