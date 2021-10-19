package main

import (
	"dasar/database"
	"fmt"
)

func main() {
	result := database.GetDatabase()
	fmt.Println(result)
}
