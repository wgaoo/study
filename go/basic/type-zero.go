package main

import (
	"fmt"
	"math"
)

type (
	name int8
)

func main() {
	var b bool
	var i int
	var i32 int32
	var f float32
	var s string
	var ia [1]int

	fmt.Println(b)
	fmt.Println(i)
	fmt.Println(i32)
	fmt.Println(f)
	fmt.Println(s)
	fmt.Println(ia)
	fmt.Println(math.MinInt8)
	fmt.Println(math.MaxInt32)
}
