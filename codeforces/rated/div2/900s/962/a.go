package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func scan(sc *bufio.Scanner, el *int) {
	sc.Scan()
	// fmt.Printf("text = %v\n", sc.Text())
	text := sc.Text()
	// fmt.Printf("text = %v\n", text)
	num, err := strconv.Atoi(text)
	if err != nil {
		fmt.Println(err)
	}
	*el = num
	return
}

func scanArray(sc *bufio.Scanner, arr []int) {
	// fmt.Printf("arr = %v\n", arr)
	sc.Scan()
	text := sc.Text()
	// fmt.Printf("text = %v\n", text)
	slice := strings.Fields(text)
	// fmt.Printf("slice = %v\n", slice)
	for i := range slice {
		// fmt.Printf("slice[%v]=%v\n", i, slice[i])
		val, err := strconv.Atoi(slice[i])
		if err != nil {
			fmt.Println(err)
			os.Exit(1)
		}
		// fmt.Printf("val = %v\n", val)
		arr[i] = int(val)
		// fmt.Printf("arr[%v] = %v\n", i, arr[i])
	}
	// fmt.Printf("arr = %v\n", arr)
}

func solve(w *bufio.Writer, sc *bufio.Scanner) {
	// fmt.Println("solve")
	var n int = 0
	scan(sc, &n)
	// fmt.Scan(&n)

	var mn int = 1e9
	var mx int = 0

	var arr []int
	arr = make([]int, n)
	// fmt.Printf("n = %v\n", n)
	// fmt.Printf("arr = %v\n", arr)
	scanArray(sc, arr)
	for i := 0; i < n; i++ {
		var el int
		// fmt.Scan(&el)
		el = arr[i]
		// w.WriteString(fmt.Sprintf("arr[%v] = %v\n", i, el))
		if el < mn {
			mn = el
		}
		if el > mx {
			mx = el
		}
	}
	w.WriteString(strconv.Itoa(mx-mn) + "\n")
	// defer w.Flush()
}

func main() {
	var t int = 0
	// fmt.Scan(&t)

	w := bufio.NewWriter(os.Stdout)
	sc := bufio.NewScanner(os.Stdin)

	scan(sc, &t)

	for i := (0); i < t; i++ {
		solve(w, sc)
	}
	defer w.Flush()
}
