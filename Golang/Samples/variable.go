package main

import "fmt"

func main() {
	var v1, v2 uint = 1, 2

	var s1 string = "Hello"

	fmt.Println(v1 + v2)

	fmt.Println(s1)

	const (
		a = iota
		b = iota
		c = iota
		_
		d 
		e
		f = 100
		g
		h = iota
	)

	fmt.Println(a, b, c, d, e, f, g, h)
	// 0, 1, 2, 4, 5, 100, 100, 8
}
