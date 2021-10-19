package main

import (
	"flag"
	"fmt"
)

func main() {
	var host *string = flag.String("host", "localhost", "Put your database host")
	var user *string = flag.String("user", "localhost", "Put your database user")
	var password *string = flag.String("password", "localhost", "Put your database password")
	var number *int = flag.Int("number", 100, "Put your database number")

	flag.Parse()

	fmt.Println("host:", *host)
	fmt.Println("user:", *user)
	fmt.Println("password:", *password)
	fmt.Println("number:", *number)
}
