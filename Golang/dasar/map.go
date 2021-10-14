package main

import "fmt"

func main() {
	// var person map[string]string = map[string]string{}
	person := map[string]string{
		"name":   "Tobi",
		"addres": "Tangerang",
	}

	person["title"] = "programmer"

	fmt.Println(person)
	fmt.Println(person["name"])
	fmt.Println(person["addres"])

	var book map[string]string = make(map[string]string)
	book["title"] = "Belajar Go-lang"
	book["author"] = "Tobi"
	book["ups"] = "salah"

	fmt.Println(book)
	fmt.Println(len(book))

	delete(book, "ups")

	fmt.Println(book)
	fmt.Println(len(book))

}
