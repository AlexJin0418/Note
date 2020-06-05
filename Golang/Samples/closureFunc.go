package main

import "fmt"

func main() {
	num := 3

	// nextNum实际上是一个函数
	nextNum := getNextNum(num)

	fmt.Println(nextNum())
	fmt.Println(nextNum())
	fmt.Println(nextNum())
	fmt.Println(nextNum())
	fmt.Println(nextNum())
}

func getNextNum(num int) func() int {
	// 闭包函数可以使用外部函数的变量
	return func() int {
		num += 1
		return num
	}
}