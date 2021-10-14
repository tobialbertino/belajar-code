package main

import "fmt"

func getFullName() (string, string, string) {
	return "Tobi", "Albertino", "salahhh"
}

func main() {
	firstName, lastName, _ := getFullName()
	fmt.Println(firstName, lastName)
}
