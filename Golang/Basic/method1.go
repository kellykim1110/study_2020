package main

import (
	"fmt"
	"math"
)

/*
Golang에는 클래스가 없는 대신 리서버 인자를 갖는 함수로 메소드 정의

func (리시버 인자) 함수이름 리턴타입
*/

type Vertex struct {
	X, Y float64
}

// Abs 메소드
// 리서버 인자로 v Vertex을 받는다.
func (v Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

// 기본형 타입도 메소드 만들기 가능
type Myfloat float64

func (f Myfloat) Abs() float64 {
	if f < 0 {
		return float64(-f)
	}
	return float64(f)
}

/*
power10과 power100의 차이점

power10  Myfloat이 포인터가 아닌 리서버 인자
func (f MyFloat) power10()

power100 Myfloat이 포인터 리서버 인자
func (f *MyFloat) power100()
*/

func (f Myfloat) power10() {
	f = f * Myfloat(10)
}

func (f *Myfloat) power100() {
	*f = *f * Myfloat(100)
}

func main() {

	// 위에서 변수로 지정한 v Vertex과 f Myfloat을 정의
	v := Vertex{3, 4}
	f := Myfloat(-math.Sqrt2)

	fmt.Println("점 X,Y 를 찍어 메소드에 접근")
	fmt.Println("v.Abs():", v.Abs())

	fmt.Println("numeric type도 메소드 정의가 가능")
	fmt.Println("f.Abs():", f.Abs())

	/*
		포인터 리서버 사용 유무 차이점
		기존의 f                                 -1.4142135623730951
		일반 리시버를 써서 10을 곱한 경우        -1.4142135623730951
		포인터 리시버를 써서 100을 곱한 경우     -141.4213562373095
	*/
	fmt.Println("포인터 리서버 사용 유무 차이점")
	fmt.Println("기존의 f\t\t\t\t", f)

	f.power10()
	fmt.Println("일반 리시버를 써서 10을 곱한 경우\t", f)

	f.power100()
	fmt.Println("포인터 리시버를 써서 100을 곱한 경우\t", f)
}
