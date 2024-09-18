package main

import "fmt"

func main() {
	var n int
	_, err := fmt.Scan(&n)
	if err != nil {
		fmt.Printf("err = %v\n", n)
	}

	var grid [][]int

	grid = make([][]int, n)
	for i := range grid {
		grid[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		var row string
		_, err = fmt.Scan(&row)
		rowLen := len(row)
		for j := range row {

			if row[j] == 'o' {
				if j+1 < rowLen {
					grid[i][j+1] += 1
				}
				if j-1 >= 0 {
					grid[i][j-1] += 1
				}
				if i-1 >= 0 {
					grid[i-1][j] += 1
				}
				if i+1 < n {
					grid[i+1][j] += 1
				}
			}
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j]%2 == 1 {
				fmt.Printf("NO\n")
				return
			}
		}
	}
	fmt.Printf("YES\n")
}
