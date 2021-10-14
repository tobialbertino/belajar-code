package main

import "fmt"

func getFullName() (firstName string, lastName string) {
	firstName = "Tobi"
	lastName = "Albertino"

	return
}

func main() {
	a, b := getFullName()
	fmt.Println(a)
	fmt.Println(b)
}
