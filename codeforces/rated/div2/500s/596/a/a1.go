package main

import "fmt"

func main() {
	var a int
	var b int

	cnt, err := fmt.Scan(&a, &b)
	if cnt != 2 {
		fmt.Printf("enter two numbers, err = %v\n", err)
		return
	}

	if a == b {
		fmt.Println(a*10 + 1)
		fmt.Println(b*10 + 2)
	} else if a == b-1 {
		fmt.Println(a*10 + 9)
		fmt.Println(b * 10)
	} else if a == 9 && b == 1 {
		fmt.Println(9)
		fmt.Println(10)
	} else {
		fmt.Println(-1)
	}
}
