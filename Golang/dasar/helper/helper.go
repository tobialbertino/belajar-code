package helper

import "fmt"

// di mulai dari huruf besar maka bisa diakses ke semua
func SayHello() {
	fmt.Println("Hello world!")
}

// tidak di export karena nama func diawali huruf kecil
func sayWorld() {
	fmt.Println("Hello world!")
}

var version = "1.0.0" // tidak bisa diakses
var App = "Golang"
