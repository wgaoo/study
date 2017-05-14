// map in go

package main

import "fmt"

func main() {
	var m map[int]string
	m = make(map[int]string)
	m[1] = "one"
	a := m[1]
	fmt.Println(a)
}
