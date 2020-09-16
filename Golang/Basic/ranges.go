package main

import "fmt"

var pow = []int{1, 2, 4, 8, 16, 32, 64, 128}

func main() {
	// range문을 사용하여 슬라이스나 맵을 이용하여 이터레이트 가능
	for i, v := range pow {
		fmt.Printf("2**%d = %d\n", i, v)
	}

	//인덱스가 필요없는 경우 _로 비워둘 수 있습니다.
	for _, v := range pow {
		fmt.Println(v)
	}
}
