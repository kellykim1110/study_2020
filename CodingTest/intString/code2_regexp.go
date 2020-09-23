// http://pyrasis.com/book/GoForTheReallyImpatient/Unit48
// https://mingrammer.com/gobyexample/regular-expressions/

package main

import (
	"fmt"
	"regexp"
)

func main() {
	s := "1234"
	//s := "a345"
	if solution(s) {
		fmt.Println("true")
	} else {
		fmt.Println("false")
	}
}

func solution(s string) bool {
	if (len(s) == 4) || (len(s) == 6) {
		// 정규표현식 이용
		if regexp.MustCompile("^[0-9]+$").MatchString(s) == true {
			return true
		}
	}
	return false
}
