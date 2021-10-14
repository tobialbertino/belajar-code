/**
multiline comment
*/

package main

import "fmt"

func endApp() {
	message := recover()
	if message != nil {
		fmt.Println("error dengan message:", message)
	}
	fmt.Println("App selesai")
}

func runApp(error bool) {
	defer endApp()
	if error {
		panic("APLIKASI ERROR")
	}
	fmt.Println("Aplikasi berjalan")
}

func main() {
	runApp(false)
	runApp(true)

	// karena ada recover, code dibawah tetap berjalan
	fmt.Println("Tobi")
}
