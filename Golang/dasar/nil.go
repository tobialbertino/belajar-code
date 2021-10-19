package main

import "fmt"

func newMap(name string) map[string]string {
	if name == "" {
		return nil
	}

	return map[string]string{
		"name": name,
	}
}

func main() {
	var person map[string]string = newMap("")
	if person == nil {
		fmt.Println("Data kosong")
	} else {
		fmt.Println(person)
	}
}
