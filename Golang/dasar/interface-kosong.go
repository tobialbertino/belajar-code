package main

import "fmt"

// mirip
// type Apapun interface{

// }

func Ups(i int) interface{} {
	if i == 1 {
		return 1
	}
	if i == 2 {
		return true
	}
	return "Ups"
}

func main() {
	var data interface{} = Ups(2)
	fmt.Println(data)
}
