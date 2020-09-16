package main

/*
인터페이스는 메소드의 집합으로,
인터페이스 타입 값은 메소드를 구현하는 값을 담을 수 있으며,
타입이 인터페이스에 메소드를 구현하면 자동으로 그 인터페이스도 구현한 게 된다.

인터페이스 값은 value와 구체적인 타입으로 구성된 tuple이라 생각하면 된다.

// 인터페이스 정의
type myinterface interface {
    myfunction() int
}

// 메소드 구현
// 인터페이스 구현(interface의 myfunction() 사용)
type MyInt int
func (rcv MyInt) myfunction() int {
    return 0
}


var a myinterface = MyInt(3)
*/

import (
	"fmt"
	"math"
)

type I interface {
	M()
}

type T struct {
	S string
}

/*
i = &T{"Hello"}에 대해
인터페이스의 (값, 타입) : (&{Hello}, *main.T)
Hello
i = F(math.Pi)에 대해
인터페이스의 (값, 타입) : (3.141592653589793, main.F)
3.141592653589793
*/

//별도의 키워드를 쓰지 않고 T가 인터페이스 I를 구현
func (t *T) M() {
	fmt.Println(t.S)
}

type F float64

//별도의 키워드를 쓰지 않고 F가 인터페이스 I를 구현
func (f F) M() {
	fmt.Println(f)
}

func main() {
	var i I

	fmt.Println("i = &T{\"Hello\"}에 대해")
	i = &T{"Hello"}
	describe(i)
	i.M()

	fmt.Println("i = F(math.Pi)에 대해")
	i = F(math.Pi)
	describe(i)
	i.M()
}

func describe(i I) {
	fmt.Printf("인터페이스의 (값, 타입) : (%v, %T)\n", i, i)
}
