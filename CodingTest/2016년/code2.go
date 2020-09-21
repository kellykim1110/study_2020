package main

import "fmt"

func main() {
	day1 := [7]string{"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"}
	day2 := [7]string{"목", "금", "토", "일", "월", "화", "수"}

	for i := 0; i < 7; i++ {
		if day1[i] == solution(5, 24) {
			fmt.Println("2016년 5월 24일은", day2[i], "요일이다.")
		}
	}
}
func solution(a int, b int) string {
	days := [12]int{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}

	day := [7]string{"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"}

	sum := 0
	for i := 0; i < a-1; i++ {
		sum += days[i]
	}
	sum += b

	date := sum % 7
	return day[date]
}
