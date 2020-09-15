package main

import "fmt"

/*
switch는 위에서 아래로 case를 검사하며,
break를 하지 않아도 자동으로 case 종료 가능

switch i {
case 0:
case f():
}

위의 코드는 i==0이면 f()는 실행되지 않음을 의미

fallthrough를 끝에 추가하면 case가 종료되지 않음
*/

func main() {
	fmt.Println("이번 학기 나의 성적은 ")
	score := 3.98
	yes_fallthrough(score)
	no_fallthrough(score)
}

func no_fallthrough(score float64) {
	var grade string
	switch {
	case score > 4.0:
		grade = "A"
	case score > 3.5:
		grade = "B"
	case score > 3.0:
		grade = "C"
	default:
		grade = "D"
	}
	fmt.Println("fallthrough를 쓰지 않으면", grade, "이다.")
}

func yes_fallthrough(score float64) {
	var grade string
	switch {
	case score > 4.0:
		grade = "A"
	case score > 3.5:
		grade = "B"
	case score > 3.0:
		grade = "C"
		fallthrough
	default:
		grade = "D"
	}
	fmt.Println("fallthrough를 쓰면", grade, "이다.")
}
