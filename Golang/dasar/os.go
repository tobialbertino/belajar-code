package main

import (
	"fmt"
	"os"
)

func main() {
	args := os.Args
	fmt.Println("Arguments:")
	fmt.Println(args)

	name, err := os.Hostname()
	if err == nil {
		fmt.Println("Hostname:", name)
	} else {
		fmt.Println("Error:", err)
	}

	username := os.Getenv("USERNAME")
	password := os.Getenv("PASSWORD")

	fmt.Println(username)
	fmt.Println(password)
}
