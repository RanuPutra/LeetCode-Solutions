package main

import "strings"

func createGrid(m int, n int) []string {
	grid := make([]string, m)
	for i := 0; i < m; i++ {
		if i == 0 {
			grid[i] = strings.Repeat(".", n)
		} else {
			grid[i] = strings.Repeat("#", n-1) + "."
		}
	}
	return grid
}
