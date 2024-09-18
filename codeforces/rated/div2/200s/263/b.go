package main

import "fmt"

const (
	a = 7
	b
	c
)

func main() {
	a := []string{"a", "b", "c", "d", "e"}
	a = nil
	fmt.Println(a, len(a), cap(a))

}
