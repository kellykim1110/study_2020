package main

import "fmt"

/*
맵은 key에 value를 지정하는 자료형

맵을 만들 때에는 make함수를 써야 하며
zero value는 nil이다.

key값에 접근할 때에는 맵 변수[키]와 같이 접근해야 한다.

맵 리터럴은 구조체 리터럴에 key를 추가한 것과 같고,
맵 리터럴은 make함수가 필요 없다.
*/

type Vertex struct {
	Lat, Long float64
}

func main() {
	fmt.Println("map 사용")
	// map[string] 타입 변수 선언
	var mymap map[string]Vertex
	//make()로 맵 생성
	mymap = make(map[string]Vertex)
	mymap["Bell Labs"] = Vertex{
		40.23453, -74.27876,
	}
	fmt.Println("mymap[\"Bell Labs\"]: ", mymap["Bell Labs"])

	fmt.Println("map literal 사용")
	var map_literal = map[string]Vertex{
		"Bell Labs": Vertex{
			40.23453, -74.27876,
		},
		"Google": Vertex{
			37.42202, -122.08408,
		}, // 마지막에 콤마(,)
	}
	fmt.Println("map_literal[\"Bell Labs\"]", map_literal["Bell Labs"])
}
