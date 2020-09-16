package main

import (
	"fmt"
	"math"
)

func compute(fn func(float64, float64) float64) float64 { // 함수값를 입력으로 받아서 출력
	return fn(3, 4)
}

func main() {
	// hypot 함수 정의
	hypot := func(x, y float64) float64 {
		return math.Sqrt(x*x + y*y)
	}
	fmt.Println("변수를 통해 함수 호출", hypot(5, 12))

	fmt.Println("함수를 함수에 인자로 전달")
	fmt.Println("함수를 함수에 인자로 전달")
	fmt.Println("compute(htpot):\t\t", compute(hypot))
	fmt.Println("compute(math.Pow):\t", compute(math.Pow))
}
