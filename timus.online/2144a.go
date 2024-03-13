package main

import (
	"fmt"
	"sort"
)

func main() {
	// fmt.Printf("hi suraj\n")
	var n int
	fmt.Scan(&n)

	var ans string

	var pii [][]int
	pii = make([][]int, n)

	for i := 0; i < n; i++ {
		// fmt.Printf("i = %d\n", i)
		var k int
		fmt.Scan(&k)
		var arr []int
		for j := 0; j < k; j++ {
			// fmt.Printf("j = %d\n", j)
			var a int
			fmt.Scan(&a)
			// fmt.Printf("a = %d\n", a)
			arr = append(arr, a)
			// fmt.Printf("arr = %v\n", arr)
			if j == 0 {
				pii[i] = append(pii[i], a)
			}
			if j == k-1 {
				pii[i] = append(pii[i], a)
			}
		}

		if !sort.IntsAreSorted(arr) {
			ans = "NO"
		}
	}

	if ans == "NO" {
		fmt.Println(ans)
		return
	}

	sort.Slice(pii, func(i int, j int) bool {
		if pii[i][0] < pii[j][0] {
			return true
		} else {
			return pii[i][1] < pii[j][1]
		}
	})

	for i := 1; i < n; i++ {
		first := pii[i][0]
		prev := pii[i-1][1]
		if first < prev {
			fmt.Println("NO")
			return
		}
	}

	fmt.Println("YES")

}
