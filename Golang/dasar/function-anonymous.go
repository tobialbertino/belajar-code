package main

import "fmt"

type Blacklist func(string) bool

func registerUser(name string, blacklist Blacklist) {
	if blacklist(name) {
		fmt.Println("You are blocked")
	} else {
		fmt.Println("Welcome", name)
	}
}

// func blacklist(name string) bool {
// 	return name == "Admin"
// }

// func blacklist(name string) bool {
// 	return name == "root"
// }

func main() {
	blacklist := func(name string) bool {
		return name == "Admin"
	}

	registerUser("Admin", blacklist)
	registerUser("Tobi", blacklist)

	registerUser("root", func(name string) bool {
		return name == "root"
	})
}
