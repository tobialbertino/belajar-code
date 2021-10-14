package main

import "fmt"

func logging() {
	fmt.Println("selesai memanggil function")
}

func runApp(value int) {
	defer logging()
	fmt.Println("Menjalanjan App...")
	result := 10 / value
	fmt.Println(result)
}

func main() {
	runApp(0)
}
