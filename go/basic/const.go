package main

import (
	"fmt"
)

const a int = 1
const b = 'A'

const (
	c = a
	d
	e = a + 2
	f = iota
	g = iota
)

func main() {
	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(c)
	fmt.Println(d)
	fmt.Println(e)
	fmt.Println(f)
	fmt.Println(g)
}
