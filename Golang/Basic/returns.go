package main

import "fmt"

// return 뒤에 리턴 타입 적기
func divide1(dividend, divisor int)(int,int){
	var quotient = (int) (dividend/divisor)
	var remainder = dividend%divisor
	return quotient, remainder
} 

// return 뒤에 리턴할 변수 선언하기
func divide2(dividend, divisor int)(quotient, remainder int){
	quotient = (int)(dividend/divisor)
	remainder = dividend%divisor
	return  //return만 적어도 미리 리턴할 변수를 선언했기 때문에 선언했던 변수 quotient, remainder이 호출된다.
}

func main(){
	// return 뒤에 리턴 타입을 적을 경우
	var quotient, remainder int // 다시 변수 선언 후
	quotient, remainder = divide1(11,3)
	fmt.Println("11 나누기 3의 몫은 ",quotient," 나머지는 ",remainder,"이다.")

	quotient, remainder = divide2(11,3)
	fmt.Println("11 나누기 3의 몫은 ",quotient," 나머지는 ",remainder,"이다.")
}