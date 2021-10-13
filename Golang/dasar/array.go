package main

import "fmt"

func main() {
	var names [2]string
	names[0] = "Tobi"
	names[1] = "Albertino"

	fmt.Println(names[0])
	fmt.Println(names[1])

	var values = [3]int{
		10, 25, 50,
	}

	fmt.Println(values)
	fmt.Println(len(values))
	fmt.Println(len(names))
}
