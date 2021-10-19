package main

import (
	"container/list"
	"fmt"
)

func main() {
	data := list.New()

	data.PushBack("Tobi")
	data.PushBack("Albertino")
	data.PushFront("Budi")

	fmt.Println(data.Front().Value)
	fmt.Println(data.Back().Value)

	for element := data.Front(); element != nil; element = element.Next() {
		fmt.Println(element.Value)
	}
}
