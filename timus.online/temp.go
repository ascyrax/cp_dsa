package main

import (
	"fmt"
)

// func service() {
// 	fmt.Println("hello from service")
// }

// func makeSquares(array [3]int) {
// 	for index, elem := range array {
// 		array[index] = elem * elem
// 	}
// }

// type Shape interface {
// 	Area() float64
// 	Perimeter() float64
// }

// type Rect struct {
// 	width  float64
// 	height float64
// }

// func (r *Rect) Area() float64 {
// 	return r.width * r.height
// }

// func (r *Rect) Perimeter() float64 {
// 	return 2 * (r.width + r.height)
// }

func squares(c chan int) {
	for i := 0; i < 4; i++ {
		num := <-c
		fmt.Println(num * num)
	}
}

type S struct {
	a, b, c string
}

func main() {

	// a := [...]int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	// s := a[2:4]
	// newS := append(s, 55, 66)
	// fmt.Printf("len=%d cap=%d\n", len(newS), cap(newS))

	// var s1 []int
	// s2 := []int{1, 2, 3}
	// n1 := copy(s1, s2)
	// fmt.Printf("n1=%d, s1=%v, s2=%v\n", n1, s1, s2)
	// fmt.Println("s1 == nil", s1 == nil)

	// fmt.Println("main() started")
	// go service()
	// select {}
	// fmt.Println("main stopped")

	// a := [3]int{0, 1, 2}
	// makeSquares(a)

	// fmt.Println(a)

	// r := Rect{5.0, 4.0}
	// var s Shape = r
	// area := S.Area()
	// fmt.Println(area)

	// c := make(chan int, 3)
	// go squares(c)

	// fmt.Print(runtime.NumGoroutine())

	// c <- 1
	// c <- 2
	// c <- 3
	// c <- 4

	// fmt.Print(runtime.NumGoroutine())

	x := interface{}(&S{"a", "b", "c"})
	y := interface{}(&S{"a", "b", "c"})
	fmt.Println(x == y)

	a := []string{"A", "B", "C", "D", "E"}
	a = a[:0]
	fmt.Println(a, len(a), cap(a))
}
