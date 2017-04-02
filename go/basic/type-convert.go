package main

import "fmt"
import "strconv"

type (
	byte     int8
	rune     int32
	ByteSize int64
)

func main() {
	var a float32 = 100.1
	fmt.Println(a)
	b := int32(a)
	fmt.Println(b)

	var iTmp int = 65
	var s string = string(iTmp)
	fmt.Println(s)
	var ss string = strconv.Itoa(iTmp)
	fmt.Println(ss)
}
