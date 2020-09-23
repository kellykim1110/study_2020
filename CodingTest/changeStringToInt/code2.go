// 자료형 변환
// https://leo-bb.tistory.com/32
package main

import (
	"fmt"
	"reflect"
	"strconv"
)

func main() {
	fmt.Println("자료형이 ", reflect.TypeOf(solution("1234")), "인 ", solution("1234"))
	fmt.Println("자료형이 ", reflect.TypeOf(solution("+1234")), "인 ", solution("+1234"))
	fmt.Println("자료형이 ", reflect.TypeOf(solution("-1234")), "인 ", solution("-1234"))
}

func solution(s string) int {
	str2int, _ := strconv.Atoi(s)
	return str2int
}
