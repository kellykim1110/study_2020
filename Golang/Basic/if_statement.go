package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(sqrt(4))
	fmt.Println(sqrt(-4))
	fmt.Println(pow(3, 2, 10))
}

func sqrt(x float64) string {
	if x < 0 {
		return sqrt(-x) + "i"
	} else { ////else문은 if문이 닫히는(}) 줄과 함께 쓰여야 합니다.
		return fmt.Sprint(math.Sqrt(x))
	}
}

func pow(x, n, lim float64) float64 {
	if v := math.Pow(x, n); v < lim { // power in mathmatics is x^n
		return v
	}
	return lim
}
