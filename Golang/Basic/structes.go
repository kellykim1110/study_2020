package main

/*
구조체는 필드들의 집합
type struct_name struct {}
구조체 필드는 '.'으로 접근 가능
구조체 인스턴스 생성시 특정 필드만 초기화하고 싶으면
<초기화할 필드> : <초기화할 값>  을 지정
*/

import "fmt"

type Vertex struct {
	X int
	Y int
}

// 구조체 인스턴스 선언하는 법
var (
	//방법1. X가 1, Y가 2로 초기화
	v1 = Vertex{1, 2}

	//방법2. X만 지정하고 Y는 int에 zero value
	v2 = Vertex{X: 1}

	//방법3. X, Y 모두 int에 zero value
	v3 = Vertex{}
)

func main() {
	fmt.Println("v1.X값:", v1.X)
	v1.X = 4
	fmt.Println("v1.X를 4로 바꾸었다. v1.X=", v1.X)

	// 구조체 포인터로 구조체 값 바꾸기
	var p = &v1
	p.X = 10
	fmt.Println("포인터로 v1.X의 값을 바꾸어서 v1.X=", v1.X)
}
