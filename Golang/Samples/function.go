package main

import "fmt"

func main() {
	// var a, b = 1, 2
	a, b := 30, 24

	var result int

	result = maxNum(a, b)

	if result == 0 {
		fmt.Println("Equal")
	} else if result == 1 {
		fmt.Println("a is larger")
	} else {
		fmt.Println("b is larger")
	}

	x, y := "Amazon", "Google"

	fmt.Println(swap(x, y))

	num1, num2 := 11, 22

	fmt.Printf("Make swap: %d with %d\n", num1, num2)

	// Use reference to change the true value
	numSwap(&num1, &num2)

	fmt.Printf("After swap: %d with %d\n", num1, num2)
}

func maxNum(a, b int) int {
	var result int

	if a > b {
		result = 1
	} else if b > a {
		result = 2
	} else {
		result = 0
	}

	return result
}

// Do a swap operation for x and y, return multiple strings
func swap(x, y string) (string, string) {
	return y, x
}

func numSwap(num1 *int, num2 *int) {
	var temp int

	temp = *num1
	*num1 = *num2
	*num2 = temp
}