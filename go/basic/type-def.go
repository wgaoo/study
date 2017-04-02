package main

import (
	"fmt"
)

// 在全局变量的申明中，不允许使用：
// :代替var关键字存在
func main() {
	var b = 1
	c := 1             //可以自动推断
	var cc float32 = 2 // 推断错误
	d := false
	fmt.Println(b)
	fmt.Println(c)
	fmt.Println(cc)
	fmt.Println(d)

	var i, _, k int = 1, 2, 3 // 空白符号，应对函数的多返回值
	fmt.Println(i, k)
}
