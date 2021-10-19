package main

import (
	"fmt"
)

func random() interface{} {
	return "It's string"
}

func main() {
	var result interface{} = random()
	// var resultString string = result.(string)
	// fmt.Println(resultString)

	switch value := result.(type) {
	case string:
		fmt.Println("value", value, "Is String")
	case int:
		fmt.Println("value", value, "Is int")
	default:
		fmt.Println("unknown value")

	}
}
