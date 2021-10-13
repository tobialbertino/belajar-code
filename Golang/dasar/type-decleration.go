package main

import "fmt"

func main() {
	type noKTP string

	var noKtpTobi noKTP = "123456789"

	fmt.Println(noKtpTobi)
}
