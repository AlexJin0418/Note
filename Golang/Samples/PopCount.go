package main

import "fmt"
import "crypto/sha256"
import "crypto/sha512"

func main() {
	pwd := "abc"

	c1 := sha512.Sum512([]byte(pwd))

	c2 := sha256.Sum256([]byte([pwd]))

	fmt.Printf("sha256: %x\n", c2)

	fmt.Printf("sha512: %x\n", c1)
}