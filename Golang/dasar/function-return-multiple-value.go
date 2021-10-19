package main

import "fmt"

func getFullNamee() (string, string, string) {
	return "Tobi", "Albertino", "salahhh"
}

func main() {
	firstName, lastName, _ := getFullNamee()
	fmt.Println(firstName, lastName)
}
