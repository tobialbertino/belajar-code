package main

import "fmt"

func logging() {
	fmt.Println("selesai memanggil function")
}

func runApps(value int) {
	defer logging()
	fmt.Println("Menjalanjan App...")
	result := 10 / value
	fmt.Println(result)
}

func main() {
	runApps(0)
}
