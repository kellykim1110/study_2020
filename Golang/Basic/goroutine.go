package main

import (
	"fmt"
	"time"
)

/*
goroutine은 Go runtime이 담당하는 경량 쓰레드  lightweight thread이다.

go f(x,y,z)
- f,x,y,z의 값을 구하는 것은 현재의 goroutine에서 진행되고
- f를 실행하는 것은 새로운 goroutine에서 진행된다.

주의) goroutine은 같은 주소 공간을 쓰기 때문에
shared memory에 접근할 때 동기화해줘야 한다.
*/

// goroutine에 사용할 함수를 정의
func say(s string) {
	for i := 0; i < 5; i++ {
		time.Sleep(100 * time.Millisecond)
		fmt.Println(s)
	}
}

func main() {
	go say("이건 다른 루틴이다.")
	say("이건 본래 루틴")
}
