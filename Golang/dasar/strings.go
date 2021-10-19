package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(strings.Contains("Tobi Albertino", "Tobi")) // true
	fmt.Println(strings.Contains("Tobi Albertino", "Budi")) // false

	fmt.Println(strings.Split("Tobi Albertino", " "))

	fmt.Println(strings.ToLower("Tobi Albertino"))
	fmt.Println(strings.ToUpper("Tobi Albertino"))
	fmt.Println(strings.ToTitle("tobi albertino"))

	fmt.Println(strings.Trim("    Tobi Albertino     ", " "))
	fmt.Println(strings.ReplaceAll("tobitobijokotobi tobi tobi", "tobi", "budi"))

}
